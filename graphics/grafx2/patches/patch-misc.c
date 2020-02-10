$NetBSD: patch-misc.c,v 1.3 2020/02/10 13:08:10 ryoon Exp $

* Fix sysctl build failure

--- misc.c.orig	2020-02-06 21:01:27.000000000 +0000
+++ misc.c
@@ -29,6 +29,9 @@
 #ifndef _MSC_VER
 #include <strings.h>
 #endif
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE
+#endif
 #include <stdlib.h>
 #include <math.h>
 #if !defined(USE_SDL) && !defined(USE_SDL2)
