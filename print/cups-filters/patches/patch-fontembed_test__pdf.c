$NetBSD: patch-fontembed_test__pdf.c,v 1.1 2018/10/18 10:49:44 leot Exp $

`%m' is not supported in printf(3), use strerror(3).

--- fontembed/test_pdf.c.orig	2018-10-03 20:12:51.000000000 +0000
+++ fontembed/test_pdf.c
@@ -2,6 +2,7 @@
 #include "config.h"
 #include "sfnt.h"
 #include <assert.h>
+#include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
 
@@ -9,7 +10,7 @@ static void example_outfn(const char *bu
 {
   FILE *f=(FILE *)context;
   if (fwrite(buf,1,len,f)!=len) {
-    fprintf(stderr,"Short write: %m\n");
+    fprintf(stderr,"Short write: %s\n", strerror(errno));
     assert(0);
     return;
   }
