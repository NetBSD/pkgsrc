$NetBSD: patch-src_dispatch__common.h,v 1.6 2017/02/18 14:00:05 joerg Exp $

--- src/dispatch_common.h.orig	2017-02-06 16:00:20.000000000 +0000
+++ src/dispatch_common.h
@@ -36,7 +36,7 @@
 #define PLATFORM_HAS_GLX 0
 #define PLATFORM_HAS_WGL 0
 #else
-#define PLATFORM_HAS_EGL 1
+#define PLATFORM_HAS_EGL BUILD_EGL
 #define PLATFORM_HAS_GLX ENABLE_GLX
 #define PLATFORM_HAS_WGL 0
 #endif
