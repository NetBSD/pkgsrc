$NetBSD: patch-Source_UI_emu__sdl.cpp,v 1.1 2019/09/07 00:36:34 tsutsui Exp $

- change rom file directory to ~/.local/share/retro_pc_pi/xm8/rom

--- Source/UI/emu_sdl.cpp.orig	2015-05-15 20:47:30.000000000 +0000
+++ Source/UI/emu_sdl.cpp
@@ -14,6 +14,8 @@
 #include "common.h"
 #include "vm.h"
 #include "classes.h"
+#include "app.h"
+#include "setting.h"
 #include "video.h"
 #include "emu_sdl.h"
 
@@ -25,11 +27,12 @@
 #define EXTERNAL_PATH_ROM			"XM8/"
 								// replace from EXTERNAL_PATH_ANDROID
 
+#define USER_PATH_ROM				"rom/"
 //
 // EMU_SDL()
 // constructor
 //
-EMU_SDL::EMU_SDL(Video *v)
+EMU_SDL::EMU_SDL(App *a, Video *v)
 {
 #ifdef __ANDROID__
 	char *replace;
@@ -47,7 +50,13 @@ EMU_SDL::EMU_SDL(Video *v)
 		strcpy(replace, EXTERNAL_PATH_ROM);
 	}
 #else
+#if 0
 	strcpy(base_path, SDL_GetBasePath());
+#else
+	setting = a->GetSetting();
+	strcpy(base_path, setting->GetSettingDir());
+	strcat(base_path, USER_PATH_ROM);
+#endif
 #endif // __ANDROID__
 }
 
