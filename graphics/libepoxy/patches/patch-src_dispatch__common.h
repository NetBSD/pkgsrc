$NetBSD: patch-src_dispatch__common.h,v 1.6.2.1 2017/04/29 18:08:25 bsiegert Exp $

The generic defaults are suitable for Darwin as BUILD_EGL will be correct,
and possibly not zero.

--- src/dispatch_common.h.orig	2017-02-06 16:00:20.000000000 +0000
+++ src/dispatch_common.h
@@ -27,16 +27,12 @@
 #define PLATFORM_HAS_EGL 0
 #define PLATFORM_HAS_GLX ENABLE_GLX
 #define PLATFORM_HAS_WGL 1
-#elif defined(__APPLE__)
-#define PLATFORM_HAS_EGL 0
-#define PLATFORM_HAS_GLX ENABLE_GLX
-#define PLATFORM_HAS_WGL 0
 #elif defined(ANDROID)
 #define PLATFORM_HAS_EGL 1
 #define PLATFORM_HAS_GLX 0
 #define PLATFORM_HAS_WGL 0
 #else
-#define PLATFORM_HAS_EGL 1
+#define PLATFORM_HAS_EGL BUILD_EGL
 #define PLATFORM_HAS_GLX ENABLE_GLX
 #define PLATFORM_HAS_WGL 0
 #endif
