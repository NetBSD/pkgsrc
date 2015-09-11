$NetBSD: patch-include_EGL_eglplatform.h,v 1.2 2015/09/11 00:03:36 tnn Exp $

https://bugs.freedesktop.org/show_bug.cgi?id=90249

--- include/EGL/eglplatform.h.orig	2015-09-10 17:40:30.000000000 +0000
+++ include/EGL/eglplatform.h
@@ -104,7 +104,7 @@ typedef struct ANativeWindow        *EGL
 typedef struct egl_native_pixmap_t  *EGLNativePixmapType;
 typedef void                        *EGLNativeDisplayType;
 
-#elif defined(__unix__)
+#elif defined(__unix__) || defined(__APPLE__)
 
 #if defined(MESA_EGL_NO_X11_HEADERS)
 
