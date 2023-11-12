$NetBSD: patch-src_video_cocoa_SDL__cocoamouse.h,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts":
https://raw.githubusercontent.com/evanmiller/TigerPorts/master/devel/libsdl2/files/patch-SDL2-2.0.3_OSX_104.diff

--- src/video/cocoa/SDL_cocoamouse.h.orig	2014-03-16 02:31:41.000000000 +0000
+++ src/video/cocoa/SDL_cocoamouse.h
@@ -25,6 +25,10 @@
 
 #include "SDL_cocoavideo.h"
 
+#if !defined(MAC_OS_X_VERSION_10_5)
+typedef float CGFloat;
+#endif
+
 extern void Cocoa_InitMouse(_THIS);
 extern void Cocoa_HandleMouseEvent(_THIS, NSEvent * event);
 extern void Cocoa_HandleMouseWheel(SDL_Window *window, NSEvent * event);
