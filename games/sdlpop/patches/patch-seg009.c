$NetBSD: patch-seg009.c,v 1.1 2019/11/02 14:35:37 nia Exp $

Use installed data path.
Disable rumble/haptic support.

--- src/seg009.c.orig	2018-03-17 16:33:14.000000000 +0000
+++ src/seg009.c
@@ -34,8 +34,8 @@ void sdlperror(const char* header) {
 	//quit(1);
 }
 
-char exe_dir[POP_MAX_PATH] = ".";
-bool found_exe_dir = false;
+char *exe_dir = PKGSRC_DATA_PATH;
+bool found_exe_dir = true;
 
 void find_exe_dir() {
 	if (found_exe_dir) return;
@@ -2108,7 +2108,7 @@ void __pascal far set_gr_mode(byte grmod
 	SDL_SetHint(SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1");
 #endif
 	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_NOPARACHUTE |
-	             SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC ) != 0) {
+	             SDL_INIT_GAMECONTROLLER ) != 0) {
 		sdlperror("SDL_Init");
 		quit(1);
 	}
