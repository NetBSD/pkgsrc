$NetBSD: patch-src_libjasper_jpc_jpc__t1enc.c,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/jpc/jpc_t1enc.c.orig	2007-01-19 21:43:07.000000000 +0000
+++ src/libjasper/jpc/jpc_t1enc.c
@@ -219,7 +219,7 @@ int jpc_enc_enccblk(jpc_enc_t *enc, jas_
 
 	cblk->numpasses = (cblk->numbps > 0) ? (3 * cblk->numbps - 2) : 0;
 	if (cblk->numpasses > 0) {
-		cblk->passes = jas_malloc(cblk->numpasses * sizeof(jpc_enc_pass_t));
+		cblk->passes = jas_alloc2(cblk->numpasses, sizeof(jpc_enc_pass_t));
 		assert(cblk->passes);
 	} else {
 		cblk->passes = 0;
