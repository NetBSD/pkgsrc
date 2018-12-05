$NetBSD: patch-fontembed_test__pdf.c,v 1.2 2018/12/05 18:49:39 leot Exp $

`%m' is not supported in printf(3), use strerror(3).

--- fontembed/test_pdf.c.orig	2018-11-23 21:18:49.000000000 +0000
+++ fontembed/test_pdf.c
@@ -2,14 +2,16 @@
 #include "config.h"
 #include "sfnt.h"
 #include <assert.h>
+#include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 static void example_outfn(const char *buf,int len,void *context) // {{{
 {
   FILE *f=(FILE *)context;
   if (fwrite(buf,1,len,f)!=len) {
-    fprintf(stderr,"Short write: %m\n");
+    fprintf(stderr,"Short write: %s\n", strerror(errno));
     assert(0);
     return;
   }
