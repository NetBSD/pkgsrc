$NetBSD: patch-src_video_SDL__egl.c,v 1.1 2015/02/11 14:00:46 jmcneill Exp $

--- src/video/SDL_egl.c.orig	2014-03-16 02:31:44.000000000 +0000
+++ src/video/SDL_egl.c
@@ -29,10 +29,10 @@
 
 #if SDL_VIDEO_DRIVER_RPI
 /* Raspbian places the OpenGL ES/EGL binaries in a non standard path */
-#define DEFAULT_EGL "/opt/vc/lib/libEGL.so"
-#define DEFAULT_OGL_ES2 "/opt/vc/lib/libGLESv2.so"
-#define DEFAULT_OGL_ES_PVR "/opt/vc/lib/libGLES_CM.so"
-#define DEFAULT_OGL_ES "/opt/vc/lib/libGLESv1_CM.so"
+#define DEFAULT_EGL PREFIX "/lib/libEGL.so"
+#define DEFAULT_OGL_ES2 PREFIX "/lib/libGLESv2.so"
+#define DEFAULT_OGL_ES_PVR PREFIX "/lib/libGLES_CM.so"
+#define DEFAULT_OGL_ES PREFIX "/lib/libGLESv1_CM.so"
 
 #elif SDL_VIDEO_DRIVER_ANDROID
 /* Android */
