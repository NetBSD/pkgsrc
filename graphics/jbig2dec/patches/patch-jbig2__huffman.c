$NetBSD: patch-jbig2__huffman.c,v 1.1 2017/08/05 08:03:05 nros Exp $
* fix CVE-2017-7975
  fixed upstrema so remove this patch on the next version update.
--- jbig2_huffman.c.orig	2017-08-05 07:27:45.000000000 +0000
+++ jbig2_huffman.c
@@ -422,8 +422,8 @@ jbig2_build_huffman_table(Jbig2Ctx *ctx,
 
             if (PREFLEN == CURLEN) {
                 int RANGELEN = lines[CURTEMP].RANGELEN;
-                int start_j = CURCODE << shift;
-                int end_j = (CURCODE + 1) << shift;
+                uint32_t start_j = CURCODE << shift;
+                uint32_t end_j = (CURCODE + 1) << shift;
                 byte eflags = 0;
 
                 if (end_j > max_j) {
