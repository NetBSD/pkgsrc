$NetBSD: patch-include_EGL_eglplatform.h,v 1.1 2015/05/16 16:39:52 tnn Exp $

https://bugs.freedesktop.org/show_bug.cgi?id=90249

From 5b31c5cdcdb09d12e3dc5180ab5c80250e8dd2bd Mon Sep 17 00:00:00 2001
From: Julien Isorce <j.isorce@samsung.com>
Date: Thu, 30 Apr 2015 08:36:50 +0100
Subject: [PATCH] egl: use unix defines on osx with clang

CC       egl_dri2.lo
include/EGL/eglplatform.h:135:2:
  error: "Platform not recognized"
include/EGL/eglplatform.h:140:9:
  error: unknown type name 'EGLNativeDisplayType'
typedef EGLNativeDisplayType NativeDisplayType;

Signed-off-by: Julien Isorce <j.isorce@samsung.com>
---
 include/EGL/eglplatform.h | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git a/include/EGL/eglplatform.h b/include/EGL/eglplatform.h
index 2eb6865..672119e 100644
--- include/EGL/eglplatform.h
+++ include/EGL/eglplatform.h
@@ -104,7 +104,7 @@ typedef struct ANativeWindow        *EGLNativeWindowType;
 typedef struct egl_native_pixmap_t  *EGLNativePixmapType;
 typedef void                        *EGLNativeDisplayType;
 
-#elif defined(__unix__)
+#elif defined(__unix__) || defined(__APPLE__)
 
 #if defined(MESA_EGL_NO_X11_HEADERS)
