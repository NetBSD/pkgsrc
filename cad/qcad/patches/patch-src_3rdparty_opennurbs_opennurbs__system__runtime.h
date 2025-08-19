$NetBSD: patch-src_3rdparty_opennurbs_opennurbs__system__runtime.h,v 1.1 2025/08/19 12:52:17 plunky Exp $

they say ON_RUNTIME_LINUX but really it is POSIX

--- src/3rdparty/opennurbs/opennurbs_system_runtime.h.orig	2025-06-29 16:05:12.382568700 +0000
+++ src/3rdparty/opennurbs/opennurbs_system_runtime.h
@@ -51,7 +51,7 @@
 #define ON_RUNTIME_ANDROID
 #endif
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__NetBSD__)
 #if !defined(ON_RUNTIME_LINUX)
 #define ON_RUNTIME_LINUX
 #endif
