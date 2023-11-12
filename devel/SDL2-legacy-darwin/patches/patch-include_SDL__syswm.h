$NetBSD: patch-include_SDL__syswm.h,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts":
https://raw.githubusercontent.com/evanmiller/TigerPorts/master/devel/libsdl2/files/patch-SDL2-2.0.3_OSX_104.diff

--- include/SDL_syswm.h.orig	2014-03-16 02:31:42.000000000 +0000
+++ include/SDL_syswm.h
@@ -83,6 +83,12 @@ struct SDL_SysWMinfo;
 
 #if defined(SDL_VIDEO_DRIVER_COCOA)
 #ifdef __OBJC__
+#if defined(__ALTIVEC__) && !defined(MAC_OS_X_VERSION_10_5)
+/* to cricumvent a bug in Mac OS X 10.4 SDK */
+#define vector __vector
+#include <CoreServices/CoreServices.h>
+#undef vector
+#endif
 #include <Cocoa/Cocoa.h>
 #else
 typedef struct _NSWindow NSWindow;
