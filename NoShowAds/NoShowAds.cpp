#include <iostream>
#include <windows.h>

int main()
{
	while (TRUE)
	{
		LPCSTR Target = "\xc4\xab\xc4\xab\xbf\xc0\xc5\xe5";

		HWND h = FindWindowA(NULL, Target);
		if (h != NULL)
		{
			h = GetWindow(GetWindow(GetWindow(h, GW_CHILD), GW_HWNDNEXT), GW_HWNDNEXT);
			ShowWindow(h, SW_HIDE);
			PostMessage(h, WM_CLOSE, 0, 0);
		}
		Sleep(1000);
	}
}