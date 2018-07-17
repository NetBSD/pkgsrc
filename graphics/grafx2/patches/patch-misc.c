$NetBSD: patch-misc.c,v 1.1 2018/07/17 13:07:50 ryoon Exp $

* Fix sysctl build failure

--- misc.c.orig	2018-05-15 16:51:04.000000000 +0000
+++ misc.c
@@ -24,6 +24,9 @@
 #if defined(WIN32)
 #define _WIN32_WINNT 0x0500
 #endif
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE
+#endif
 #include <SDL.h>
 #include <string.h>
 #ifndef _MSC_VER
