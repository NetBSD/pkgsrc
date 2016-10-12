$NetBSD: patch-src_runtime_gencgc.c,v 1.1 2016/10/12 11:35:48 asau Exp $

--- src/runtime/gencgc.c.orig	2016-09-30 16:41:12.000000000 +0000
+++ src/runtime/gencgc.c
@@ -24,6 +24,10 @@
  *   <ftp://ftp.cs.utexas.edu/pub/garbage/bigsurv.ps>.
  */
 
+#if defined(__NetBSD__)
+#define _KERNTYPES
+#endif
+
 #include <stdlib.h>
 #include <stdio.h>
 #include <errno.h>
