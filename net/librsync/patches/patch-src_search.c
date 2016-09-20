$NetBSD: patch-src_search.c,v 1.1 2016/09/20 08:26:50 wiz Exp $

librsync has a crash in rs_search_for_block documented here:
https://github.com/librsync/librsync/issues/50

--- src/search.c.orig	2015-11-29 20:43:12.000000000 +0000
+++ src/search.c
@@ -218,7 +218,7 @@ rs_search_for_block(rs_weak_sum_t weak_s
 	    r = m;
     }
 
-    if (l == r) {
+    if ((l == r) && (l <= bucket->r)) {
 	int i = sig->targets[l].i;
 	rs_block_sig_t *b = &(sig->block_sigs[i]);
 	if (weak_sum != b->weak_sum)
