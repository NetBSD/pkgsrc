$NetBSD: patch-src_libjasper_jpc_jpc__mqenc.c,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/jpc/jpc_mqenc.c.orig	2007-01-19 21:43:07.000000000 +0000
+++ src/libjasper/jpc/jpc_mqenc.c
@@ -197,7 +197,7 @@ jpc_mqenc_t *jpc_mqenc_create(int maxctx
 	mqenc->maxctxs = maxctxs;
 
 	/* Allocate memory for the per-context state information. */
-	if (!(mqenc->ctxs = jas_malloc(mqenc->maxctxs * sizeof(jpc_mqstate_t *)))) {
+	if (!(mqenc->ctxs = jas_alloc2(mqenc->maxctxs, sizeof(jpc_mqstate_t *)))) {
 		goto error;
 	}
 
