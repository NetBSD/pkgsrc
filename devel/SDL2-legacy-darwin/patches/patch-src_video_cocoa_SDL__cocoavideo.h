$NetBSD: patch-src_video_cocoa_SDL__cocoavideo.h,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts":
https://raw.githubusercontent.com/evanmiller/TigerPorts/master/devel/libsdl2/files/patch-SDL2-2.0.3_OSX_104.diff

--- src/video/cocoa/SDL_cocoavideo.h.orig	2014-03-16 02:31:41.000000000 +0000
+++ src/video/cocoa/SDL_cocoavideo.h
@@ -25,6 +25,12 @@
 
 #include "SDL_opengl.h"
 
+#if defined(__ALTIVEC__) && !defined(MAC_OS_X_VERSION_10_5)
+/* to cricumvent a bug in Mac OS X 10.4 SDK */
+#define vector __vector
+#include <CoreServices/CoreServices.h>
+#undef vector
+#endif
 #include <ApplicationServices/ApplicationServices.h>
 #include <Cocoa/Cocoa.h>
 
@@ -39,6 +45,11 @@
 #include "SDL_cocoaopengl.h"
 #include "SDL_cocoawindow.h"
 
+#if !defined(MAC_OS_X_VERSION_10_5)
+typedef long int NSInteger;
+typedef unsigned int NSUInteger;
+#endif
+
 /* Private display data */
 
 @class SDLTranslatorResponder;
