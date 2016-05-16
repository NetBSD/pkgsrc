$NetBSD: patch-src_libjasper_jpc_jpc__t2cod.c,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/jpc/jpc_t2cod.c.orig	2007-01-19 21:43:07.000000000 +0000
+++ src/libjasper/jpc/jpc_t2cod.c
@@ -573,7 +573,7 @@ int jpc_pchglist_insert(jpc_pchglist_t *
 	}
 	if (pchglist->numpchgs >= pchglist->maxpchgs) {
 		newmaxpchgs = pchglist->maxpchgs + 128;
-		if (!(newpchgs = jas_realloc(pchglist->pchgs, newmaxpchgs * sizeof(jpc_pchg_t *)))) {
+		if (!(newpchgs = jas_realloc2(pchglist->pchgs, newmaxpchgs, sizeof(jpc_pchg_t *)))) {
 			return -1;
 		}
 		pchglist->maxpchgs = newmaxpchgs;
