$NetBSD: patch-src_assuan-uds.c,v 1.1.2.2 2017/05/28 08:44:18 spz Exp $

Handle _XOPEN_SOURCE correctly.

--- src/assuan-uds.c.orig	2016-06-25 14:46:53.000000000 +0000
+++ src/assuan-uds.c
@@ -21,6 +21,14 @@
 #include <config.h>
 #endif
 
+#if defined(__sun) && !defined(_XOPEN_SOURCE)
+#  if __STDC_VERSION__ - 0 < 199901L
+#define _XOPEN_SOURCE	500
+#  else
+#define _XOPEN_SOURCE	600
+#  endif
+#endif
+
 #include <stdlib.h>
 #include <stddef.h>
 #include <stdio.h>
