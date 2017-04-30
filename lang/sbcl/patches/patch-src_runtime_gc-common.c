$NetBSD: patch-src_runtime_gc-common.c,v 1.3 2017/04/30 17:24:27 asau Exp $

--- src/runtime/gc-common.c.orig	2017-04-28 09:54:14.000000000 +0000
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
