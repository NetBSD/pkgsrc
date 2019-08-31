$NetBSD: patch-src_dispatch__common.c,v 1.7 2019/08/31 13:50:09 nia Exp $

Deal with hardcoded libGL locations and versions.

--- src/dispatch_common.c.orig	2018-10-04 23:40:48.000000000 +0000
+++ src/dispatch_common.c
@@ -174,7 +174,9 @@
 #include "dispatch_common.h"
 
 #if defined(__APPLE__)
+#ifndef GLX_LIB
 #define GLX_LIB "/opt/X11/lib/libGL.1.dylib"
+#endif
 #define OPENGL_LIB "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL"
 #define GLES1_LIB "libGLESv1_CM.so"
 #define GLES2_LIB "libGLESv2.so"
@@ -189,12 +191,12 @@
 #define GLES2_LIB "libGLESv2.dll"
 #define OPENGL_LIB "OPENGL32"
 #else
-#define GLVND_GLX_LIB "libGLX.so.1"
-#define GLX_LIB "libGL.so.1"
-#define EGL_LIB "libEGL.so.1"
-#define GLES1_LIB "libGLESv1_CM.so.1"
-#define GLES2_LIB "libGLESv2.so.2"
-#define OPENGL_LIB "libOpenGL.so.0"
+#define GLVND_GLX_LIB "libGLX.so"
+#define GLX_LIB "libGL.so"
+#define EGL_LIB "libEGL.so"
+#define GLES1_LIB "libGLESv1_CM.so"
+#define GLES2_LIB "libGLESv2.so"
+#define OPENGL_LIB "libOpenGL.so"
 #endif
 
 #ifdef __GNUC__
