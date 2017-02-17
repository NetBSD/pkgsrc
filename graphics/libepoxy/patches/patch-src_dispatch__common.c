$NetBSD: patch-src_dispatch__common.c,v 1.5 2017/02/17 15:17:09 wiz Exp $

Deal with hardcoded libGL locations and versions.

--- src/dispatch_common.c.orig	2017-02-06 16:00:20.000000000 +0000
+++ src/dispatch_common.c
@@ -174,11 +174,13 @@
 #include "dispatch_common.h"
 
 #ifdef __APPLE__
+#ifndef GLX_LIB
 #define GLX_LIB "/opt/X11/lib/libGL.1.dylib"
+#endif
 #elif defined(ANDROID)
 #define GLX_LIB "libGLESv2.so"
 #else
-#define GLX_LIB "libGL.so.1"
+#define GLX_LIB "libGL.so"
 #endif
 
 #ifdef ANDROID
