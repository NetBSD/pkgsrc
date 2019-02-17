$NetBSD: patch-src_os.hpp,v 1.1 2019/02/17 12:33:40 maya Exp $

--- src/os.hpp.orig	2019-02-17 10:28:53.000000000 +0000
+++ src/os.hpp
@@ -25,6 +25,8 @@
 #define ZIG_OS_LINUX
 #elif defined(__FreeBSD__)
 #define ZIG_OS_FREEBSD
+#elif defined(__NetBSD__)
+#define ZIG_OS_NETBSD
 #else
 #define ZIG_OS_UNKNOWN
 #endif
