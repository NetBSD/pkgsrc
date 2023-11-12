$NetBSD: patch-src_file_cocoa_SDL__rwopsbundlesupport.m,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts":
https://raw.githubusercontent.com/evanmiller/TigerPorts/master/devel/libsdl2/files/patch-SDL2-2.0.3_OSX_104.diff

--- src/file/cocoa/SDL_rwopsbundlesupport.m.orig	2014-03-16 02:31:41.000000000 +0000
+++ src/file/cocoa/SDL_rwopsbundlesupport.m
@@ -21,6 +21,12 @@
 #include "../../SDL_internal.h"
 
 #ifdef __APPLE__
+#if defined(__ALTIVEC__) && !defined(MAC_OS_X_VERSION_10_5)
+/* to cricumvent a bug in Mac OS X 10.4 SDK */
+#define vector __vector
+#include <CoreServices/CoreServices.h>
+#undef vector
+#endif
 #import <Foundation/Foundation.h>
 
 #include "SDL_rwopsbundlesupport.h"
