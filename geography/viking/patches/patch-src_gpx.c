$NetBSD: patch-src_gpx.c,v 1.1 2015/12/13 20:37:31 wiedi Exp $

Fix SunOS
--- src/gpx.c.orig	2015-02-03 22:44:42.000000000 +0000
+++ src/gpx.c
@@ -30,7 +30,11 @@
 #include "config.h"
 #endif
 
+#if defined(__sun)
+#define _XOPEN_SOURCE 600
+#else
 #define _XOPEN_SOURCE /* glibc2 needs this */
+#endif
 
 #include "gpx.h"
 #include "viking.h"
