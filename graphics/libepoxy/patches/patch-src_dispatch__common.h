$NetBSD: patch-src_dispatch__common.h,v 1.2 2015/09/14 14:40:37 gdt Exp $

Override EGL detection.

--- src/dispatch_common.h.orig	2015-07-15 23:46:36.000000000 +0000
+++ src/dispatch_common.h
@@ -30,7 +30,7 @@
 #define EPOXY_IMPORTEXPORT __declspec(dllexport)
 #elif defined(__APPLE__)
 #define PLATFORM_HAS_EGL 0
-#define PLATFORM_HAS_GLX 0
+#define PLATFORM_HAS_GLX 1
 #define PLATFORM_HAS_WGL 0
 #define EPOXY_IMPORTEXPORT
 #elif defined(ANDROID)
@@ -39,7 +39,12 @@
 #define PLATFORM_HAS_WGL 0
 #define EPOXY_IMPORTEXPORT
 #else
+#include "config.h"
+#ifdef BUILD_EGL
 #define PLATFORM_HAS_EGL 1
+#else
+#define PLATFORM_HAS_EGL 0
+#endif
 #define PLATFORM_HAS_GLX 1
 #define PLATFORM_HAS_WGL 0
 #define EPOXY_IMPORTEXPORT
