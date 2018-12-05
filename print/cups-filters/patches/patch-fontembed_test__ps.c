$NetBSD: patch-fontembed_test__ps.c,v 1.2 2018/12/05 18:49:39 leot Exp $

`%m' is not supported in printf(3), use strerror(3).

--- fontembed/test_ps.c.orig	2018-11-23 21:18:49.000000000 +0000
+++ fontembed/test_ps.c
@@ -2,8 +2,10 @@
 #include "config.h"
 #include "sfnt.h"
 #include <assert.h>
+#include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 const char *emb_otf_get_fontname(OTF_FILE *otf); // TODO
 
@@ -11,7 +13,7 @@ static void example_outfn(const char *bu
 {
   FILE *f=(FILE *)context;
   if (fwrite(buf,1,len,f)!=len) {
-    fprintf(stderr,"Short write: %m\n");
+    fprintf(stderr,"Short write: %s\n", strerror(errno));
     assert(0);
     return;
   }
