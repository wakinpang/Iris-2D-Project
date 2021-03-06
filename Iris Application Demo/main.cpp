#include "Iris 2D Library.h"
using namespace Iris2D;
#pragma comment(lib, "Iris Cerise-Spinach.lib") 
IIrisApp* app = NULL;
IIrisSprite* sp = NULL;

void DecodeFunction(DWORD dwSrcData, DWORD& dwDestData, const DWORD dwKey1, const DWORD dwKey2) {
	dwDestData = dwSrcData ^ dwKey2;
	dwDestData = ~dwDestData;
	dwDestData ^= dwKey1;
}

void InitResource(){
	//GetIrisEncripedResourceManager()->AddGraphResource(L"image.dat", DecodeFunction);

	sp = GetIrisSprite();
	//sp->SetBitmap(GetIrisBitmap(L"image\\1.jpg"));
	sp->SetBitmap(GetIrisBitmap(L"image\\kurumi.jpg"));
} 

bool Display(){
	InitResource();

	bool flag = true;
	BEGIN_IRIS_SAFE_WHILE()

		if(flag){
			sp->SetX(sp->GetX() + 1);
			sp->SetY(sp->GetY() + 1);
			if (sp->GetX() == 60) {
				flag = false;
			}
		}
		else {
			sp->SetX(sp->GetX() - 1);
			sp->SetY(sp->GetY() - 1);
			if (sp->GetX() == 0) {
				flag = true;
			}
		}

		IrisGraphicsUpdate(); 
		IrisInputUpdate();
	END_IRIS_SAFE_WHILE()
	return true;
}

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE prevInstance,
	PSTR cmdLine,
	int showCmd){

	app = GetIrisApp();
	if (app->Init(hInstance, 800, 600, Display, L"My Iris App")){
		//ResourceInit();
		//ModuleIrisAudio::BgmPlay(L"media\\music\\���� �Ϥʤ� - ����.mp3", 100, 100);
		app->Run();
	}
	app->Release();
	delete app;

	return 0;
}
