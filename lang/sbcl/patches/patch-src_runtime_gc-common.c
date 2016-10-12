$NetBSD: patch-src_runtime_gc-common.c,v 1.1 2016/10/12 11:35:48 asau Exp $

--- src/runtime/gc-common.c.orig	2016-09-30 16:41:12.000000000 +0000
+++ src/runtime/gc-common.c
@@ -25,6 +25,10 @@
  *   <ftp://ftp.cs.utexas.edu/pub/garbage/bigsurv.ps>.
  */
 
+#if defined(__NetBSD__)
+#define _KERNTYPES
+#endif
+
 #include <stdio.h>
 #include <signal.h>
 #include <string.h>
