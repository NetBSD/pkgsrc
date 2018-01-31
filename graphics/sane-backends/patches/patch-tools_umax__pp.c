$NetBSD: patch-tools_umax__pp.c,v 1.1 2018/01/31 10:43:03 jperkin Exp $

Set _XOPEN_SOURCE correctly.

--- tools/umax_pp.c.orig	2013-02-23 02:00:56.000000000 +0000
+++ tools/umax_pp.c
@@ -6,7 +6,9 @@
 */
 
 /* For putenv */
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _XOPEN_SOURCE
+#endif
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
