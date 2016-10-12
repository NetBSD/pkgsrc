$NetBSD: patch-src_runtime_bsd-os.c,v 1.1 2016/10/12 11:35:48 asau Exp $

--- src/runtime/bsd-os.c.orig	2016-09-30 16:41:12.000000000 +0000
+++ src/runtime/bsd-os.c
@@ -18,6 +18,10 @@
  * files for more information.
  */
 
+#if defined(__NetBSD__)
+#define _KERNTYPES
+#endif
+
 #include <stdio.h>
 #include <sys/param.h>
 #include <sys/file.h>
