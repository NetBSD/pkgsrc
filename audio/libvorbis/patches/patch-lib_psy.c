$NetBSD: patch-lib_psy.c,v 1.1 2018/08/06 13:25:38 snj Exp $

CVE-2017-14160: fix bounds check on very low sample rates.

https://github.com/xiph/vorbis/commit/018ca26dece618457dd13585cad52941193c4a25#diff-3b415297c1f1559ee10baa1284561e46

--- lib/psy.c.orig	2018-08-06 06:10:59.234730587 -0700
+++ lib/psy.c	2018-08-06 06:13:28.935699414 -0700
@@ -602,8 +602,9 @@ static void bark_noise_hybridmp(int n,co
   for (i = 0, x = 0.f;; i++, x += 1.f) {
 
     lo = b[i] >> 16;
-    if( lo>=0 ) break;
     hi = b[i] & 0xffff;
+    if( lo>=0 ) break;
+    if( hi>=n ) break;
 
     tN = N[hi] + N[-lo];
     tX = X[hi] - X[-lo];
