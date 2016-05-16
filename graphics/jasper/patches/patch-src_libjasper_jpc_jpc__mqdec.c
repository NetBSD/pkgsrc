$NetBSD: patch-src_libjasper_jpc_jpc__mqdec.c,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/jpc/jpc_mqdec.c.orig	2007-01-19 21:43:07.000000000 +0000
+++ src/libjasper/jpc/jpc_mqdec.c
@@ -118,7 +118,7 @@ jpc_mqdec_t *jpc_mqdec_create(int maxctx
 	mqdec->in = in;
 	mqdec->maxctxs = maxctxs;
 	/* Allocate memory for the per-context state information. */
-	if (!(mqdec->ctxs = jas_malloc(mqdec->maxctxs * sizeof(jpc_mqstate_t *)))) {
+	if (!(mqdec->ctxs = jas_alloc2(mqdec->maxctxs, sizeof(jpc_mqstate_t *)))) {
 		goto error;
 	}
 	/* Set the current context to the first context. */
