$NetBSD: patch-mozilla_ipc_chromium_src_build_build__config.h,v 1.1 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/ipc/chromium/src/build/build_config.h.orig	2016-04-07 21:33:19.000000000 +0000
+++ mozilla/ipc/chromium/src/build/build_config.h
@@ -30,6 +30,8 @@
 #define OS_NETBSD 1
 #elif defined(__OpenBSD__)
 #define OS_OPENBSD 1
+#elif defined(__sun)
+#define OS_SOLARIS 1
 #elif defined(_WIN32)
 #define OS_WIN 1
 #else
@@ -45,7 +47,7 @@
 
 // For access to standard POSIX features, use OS_POSIX instead of a more
 // specific macro.
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
 #define OS_POSIX 1
 #endif
 
