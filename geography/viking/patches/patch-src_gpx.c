$NetBSD: patch-src_gpx.c,v 1.2 2019/01/22 15:28:45 gdt Exp $

This is a build fix for SunOS.
\todo Explain why, and if the new __sun way is correct in general.
\todo File upstream.

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
