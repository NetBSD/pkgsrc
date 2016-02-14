$NetBSD: patch-ipc_chromium_src_build_build__config.h,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- ipc/chromium/src/build/build_config.h.orig	2013-05-11 19:19:32.000000000 +0000
+++ ipc/chromium/src/build/build_config.h
@@ -27,6 +27,8 @@
 #define OS_NETBSD 1
 #elif defined(__OpenBSD__)
 #define OS_OPENBSD 1
+#elif defined(__sun)
+#define OS_SOLARIS 1
 #elif defined(_WIN32)
 #define OS_WIN 1
 #else
@@ -42,7 +44,7 @@
 
 // For access to standard POSIX features, use OS_POSIX instead of a more
 // specific macro.
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
 #define OS_POSIX 1
 #endif
 
