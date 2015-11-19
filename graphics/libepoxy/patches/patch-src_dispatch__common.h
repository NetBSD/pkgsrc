$NetBSD: patch-src_dispatch__common.h,v 1.3 2015/11/19 11:46:33 adam Exp $

Override EGL and GLX detection.

--- src/dispatch_common.h.orig	2015-07-15 23:46:36.000000000 +0000
+++ src/dispatch_common.h
@@ -22,6 +22,7 @@
  */
 
 #include <stdbool.h>
+#include "config.h"
 
 #ifdef _WIN32
 #define PLATFORM_HAS_EGL 0
@@ -30,7 +31,11 @@
 #define EPOXY_IMPORTEXPORT __declspec(dllexport)
 #elif defined(__APPLE__)
 #define PLATFORM_HAS_EGL 0
+#ifdef BUILD_GLX
+#define PLATFORM_HAS_GLX 1
+#else
 #define PLATFORM_HAS_GLX 0
+#endif
 #define PLATFORM_HAS_WGL 0
 #define EPOXY_IMPORTEXPORT
 #elif defined(ANDROID)
@@ -39,7 +44,11 @@
 #define PLATFORM_HAS_WGL 0
 #define EPOXY_IMPORTEXPORT
 #else
+#ifdef BUILD_EGL
 #define PLATFORM_HAS_EGL 1
+#else
+#define PLATFORM_HAS_EGL 0
+#endif
 #define PLATFORM_HAS_GLX 1
 #define PLATFORM_HAS_WGL 0
 #define EPOXY_IMPORTEXPORT
