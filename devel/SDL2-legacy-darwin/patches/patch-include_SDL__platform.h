$NetBSD: patch-include_SDL__platform.h,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts":
https://raw.githubusercontent.com/evanmiller/TigerPorts/master/devel/libsdl2/files/patch-SDL2-2.0.3_OSX_104.diff

--- include/SDL_platform.h.orig	2014-03-16 02:31:42.000000000 +0000
+++ include/SDL_platform.h
@@ -70,7 +70,7 @@
 /* lets us know what version of Mac OS X we're compiling on */
 #include "AvailabilityMacros.h"
 #include "TargetConditionals.h"
-#if TARGET_OS_IPHONE
+#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
 /* if compiling for iPhone */
 #undef __IPHONEOS__
 #define __IPHONEOS__ 1
@@ -80,7 +80,9 @@
 #undef __MACOSX__
 #define __MACOSX__  1
 #if MAC_OS_X_VERSION_MIN_REQUIRED < 1050
+#if 0
 # error SDL for Mac OS X only supports deploying on 10.5 and above.
+#endif
 #endif /* MAC_OS_X_VERSION_MIN_REQUIRED < 1050 */
 #endif /* TARGET_OS_IPHONE */
 #endif /* defined(__APPLE__) */
