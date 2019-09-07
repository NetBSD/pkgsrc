$NetBSD: patch-Source_UI_app.cpp,v 1.1 2019/09/07 00:36:34 tsutsui Exp $

- change rom file directory to ~/.local/share/retro_pc_pi/xm8/rom

--- Source/UI/app.cpp.orig	2018-01-20 05:37:58.000000000 +0000
+++ Source/UI/app.cpp
@@ -251,7 +251,7 @@ bool App::Init()
 	}
 
 	// emulator i/f wrapper
-	wrapper = new EMU_SDL(video);
+	wrapper = new EMU_SDL(this, video);
 
 	// emulator i/f
 	emu = new EMU(wrapper);
