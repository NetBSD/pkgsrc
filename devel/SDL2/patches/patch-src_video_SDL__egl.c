$NetBSD: patch-src_video_SDL__egl.c,v 1.3 2016/01/03 11:15:12 wiz Exp $

--- src/video/SDL_egl.c.orig	2016-01-02 19:56:31.000000000 +0000
+++ src/video/SDL_egl.c
@@ -40,10 +40,10 @@
 
 #if SDL_VIDEO_DRIVER_RPI
 /* Raspbian places the OpenGL ES/EGL binaries in a non standard path */
-#define DEFAULT_EGL "/opt/vc/lib/libEGL.so"
-#define DEFAULT_OGL_ES2 "/opt/vc/lib/libGLESv2.so"
-#define DEFAULT_OGL_ES_PVR "/opt/vc/lib/libGLES_CM.so"
-#define DEFAULT_OGL_ES "/opt/vc/lib/libGLESv1_CM.so"
+#define DEFAULT_EGL PREFIX "/lib/libEGL.so"
+#define DEFAULT_OGL_ES2 PREFIX "/lib/libGLESv2.so"
+#define DEFAULT_OGL_ES_PVR PREFIX "/lib/libGLESv2.so"
+#define DEFAULT_OGL_ES PREFIX "/lib/libGLESv2.so"
 
 #elif SDL_VIDEO_DRIVER_ANDROID || SDL_VIDEO_DRIVER_VIVANTE
 /* Android */
