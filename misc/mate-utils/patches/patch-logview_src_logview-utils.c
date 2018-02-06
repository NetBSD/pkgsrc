$NetBSD: patch-logview_src_logview-utils.c,v 1.1 2018/02/06 10:07:23 jperkin Exp $

Set _XOPEN_SOURCE correctly.

--- logview/src/logview-utils.c.orig	2016-04-07 14:12:36.000000000 +0000
+++ logview/src/logview-utils.c
@@ -23,8 +23,10 @@
 #include <config.h>
 #endif
 
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _XOPEN_SOURCE
 #define _XOPEN_SOURCE_EXTENDED 1 /* strptime is XPG4v2 */
+#endif
 #include <time.h>
 #include <string.h>
 #include <stdlib.h>
