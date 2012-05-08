$NetBSD: patch-ipc_chromium_src_build_build__config.h,v 1.5 2012/05/08 19:29:37 martin Exp $

# Reported upstream: https://bugzilla.mozilla.org/show_bug.cgi?id=753046

--- ipc/chromium/src/build/build_config.h.orig	2012-03-13 01:36:53.000000000 +0000
+++ ipc/chromium/src/build/build_config.h
@@ -19,17 +19,23 @@
 #define OS_MACOSX 1
 #elif defined(__linux__) || defined(ANDROID)
 #define OS_LINUX 1
+#elif defined(__NetBSD__)
+#define OS_NETBSD 1
+#elif defined(__DragonFly__)
+#define OS_DRAGONFLY 1
 #elif defined(__OpenBSD__)
 #define OS_OPENBSD 1
 #elif defined(_WIN32)
 #define OS_WIN 1
+#elif defined(__FreeBSD__)
+#define OS_FREEBSD 1
 #else
 #error Please add support for your platform in build/build_config.h
 #endif
 
 // For access to standard POSIX features, use OS_POSIX instead of a more
 // specific macro.
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 #define OS_POSIX 1
 #endif
 
