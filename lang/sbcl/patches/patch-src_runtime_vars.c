$NetBSD: patch-src_runtime_vars.c,v 1.1 2016/10/12 11:35:48 asau Exp $

--- src/runtime/vars.c.orig	2016-09-30 16:41:12.000000000 +0000
+++ src/runtime/vars.c
@@ -9,6 +9,10 @@
  * files for more information.
  */
 
+#if defined(__NetBSD__)
+#define _KERNTYPES
+#endif
+
 #include <stdio.h>
 #include <string.h>
 #include <sys/types.h>
