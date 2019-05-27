$NetBSD: patch-src_dispatch__common.c,v 1.6 2019/05/27 17:04:04 nia Exp $

Deal with hardcoded libGL locations and versions.

--- src/dispatch_common.c.orig	2017-06-06 09:55:43.000000000 +0000
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
@@ -190,7 +192,7 @@
 #define GLES1_LIB "libGLES_CM.dll"
 #define GLES2_LIB "libGLESv2.dll"
 #else
-#define EGL_LIB "libEGL.so.1"
+#define EGL_LIB "libEGL.so"
 #define GLES1_LIB "libGLESv1_CM.so.1"
 #define GLES2_LIB "libGLESv2.so.2"
 #endif
