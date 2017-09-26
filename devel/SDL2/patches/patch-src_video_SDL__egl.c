$NetBSD: patch-src_video_SDL__egl.c,v 1.5 2017/09/26 13:10:56 adam Exp $

--- src/video/SDL_egl.c.orig	2017-09-22 18:51:01.000000000 +0000
+++ src/video/SDL_egl.c
@@ -44,12 +44,12 @@
 
 #if SDL_VIDEO_DRIVER_RPI
 /* Raspbian places the OpenGL ES/EGL binaries in a non standard path */
-#define DEFAULT_EGL "/opt/vc/lib/libbrcmEGL.so"
-#define DEFAULT_OGL_ES2 "/opt/vc/lib/libbrcmGLESv2.so"
-#define ALT_EGL "/opt/vc/lib/libEGL.so"
-#define ALT_OGL_ES2 "/opt/vc/lib/libGLESv2.so"
-#define DEFAULT_OGL_ES_PVR "/opt/vc/lib/libGLES_CM.so"
-#define DEFAULT_OGL_ES "/opt/vc/lib/libGLESv1_CM.so"
+#define DEFAULT_EGL "/lib/libbrcmEGL.so"
+#define DEFAULT_OGL_ES2 "/lib/libbrcmGLESv2.so"
+#define ALT_EGL "/lib/libEGL.so"
+#define ALT_OGL_ES2 "/lib/libGLESv2.so"
+#define DEFAULT_OGL_ES_PVR "/lib/libGLES_CM.so"
+#define DEFAULT_OGL_ES "/lib/libGLESv1_CM.so"
 
 #elif SDL_VIDEO_DRIVER_ANDROID || SDL_VIDEO_DRIVER_VIVANTE
 /* Android */
