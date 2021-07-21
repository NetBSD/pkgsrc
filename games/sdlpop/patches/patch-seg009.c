$NetBSD: patch-seg009.c,v 1.2 2021/07/21 09:19:51 yhardy Exp $

Use installed data path.
Disable rumble/haptic support.

--- src/seg009.c.orig	2021-07-05 06:42:34.000000000 +0000
+++ src/seg009.c
@@ -37,8 +37,8 @@ void sdlperror(const char* header) {
 	//quit(1);
 }
 
-char exe_dir[POP_MAX_PATH] = ".";
-bool found_exe_dir = false;
+char *exe_dir = PKGSRC_DATA_PATH;
+bool found_exe_dir = true;
 
 void find_exe_dir() {
 	if (found_exe_dir) return;
@@ -2436,7 +2436,7 @@ void __pascal far set_gr_mode(byte grmod
 	SDL_SetHint(SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1");
 #endif
 	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_NOPARACHUTE |
-	             SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC ) != 0) {
+	             SDL_INIT_GAMECONTROLLER ) != 0) {
 		sdlperror("set_gr_mode: SDL_Init");
 		quit(1);
 	}
