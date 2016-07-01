$NetBSD: patch-src__build__build_config.h,v 1.1 2016/07/01 20:32:35 agc Exp $

NetBSD definitions

--- src/build/build_config.h	2015/12/30 22:23:16	1.1
+++ src/build/build_config.h	2015/12/30 22:24:35
@@ -51,6 +51,8 @@
 #define TOOLKIT_VIEWS 1
 #elif defined(__FreeBSD__)
 #define OS_FREEBSD 1
+#elif defined(__NetBSD__)
+#define OS_NETBSD 1
 #elif defined(__OpenBSD__)
 #define OS_OPENBSD 1
 #elif defined(__sun)
@@ -67,13 +69,14 @@
 
 // For access to standard BSD features, use OS_BSD instead of a
 // more specific macro.
-#if defined(OS_FREEBSD) || defined(OS_OPENBSD)
+#if defined(OS_FREEBSD) || defined(OS_OPENBSD) || defined(OS_NETBSD)
 #define OS_BSD 1
 #endif
 
 // For access to standard POSIXish features, use OS_POSIX instead of a
 // more specific macro.
 #if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_FREEBSD) ||     \
+    defined(OS_NETBSD) || \
     defined(OS_OPENBSD) || defined(OS_SOLARIS) || defined(OS_ANDROID) ||  \
     defined(OS_NACL) || defined(OS_QNX)
 #define OS_POSIX 1
