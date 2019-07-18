$NetBSD: patch-misc.c,v 1.2 2019/07/18 12:15:04 nia Exp $

* Fix sysctl build failure

--- misc.c.orig	2019-01-10 08:40:57.000000000 +0000
+++ misc.c
@@ -25,6 +25,9 @@
 #if defined(WIN32)
 #define _WIN32_WINNT 0x0500
 #endif
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE
+#endif
 #include <string.h>
 #ifndef _MSC_VER
 #include <strings.h>
