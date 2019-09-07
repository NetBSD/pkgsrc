$NetBSD: patch-Source_UI_emu__sdl.h,v 1.1 2019/09/07 00:36:34 tsutsui Exp $

- change rom file directory to ~/.local/share/retro_pc_pi/xm8/rom

--- Source/UI/emu_sdl.h.orig	2015-05-15 21:05:04.000000000 +0000
+++ Source/UI/emu_sdl.h
@@ -20,7 +20,7 @@ class Video;
 class EMU_SDL
 {
 public:
-	EMU_SDL(Video *v);
+	EMU_SDL(App *a, Video *v);
 										// constructor
 	virtual ~EMU_SDL();
 										// destructor
@@ -47,6 +47,8 @@ private:
 										// full path buffer for get_bios_path()
 	Video *video;
 										// video driver
+	Setting *setting;
+										// setting driver
 };
 
 #endif // EMU_SDL_H
