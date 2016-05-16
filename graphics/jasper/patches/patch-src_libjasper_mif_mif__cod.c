$NetBSD: patch-src_libjasper_mif_mif__cod.c,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/mif/mif_cod.c.orig	2007-01-19 21:43:05.000000000 +0000
+++ src/libjasper/mif/mif_cod.c
@@ -438,8 +438,7 @@ static int mif_hdr_growcmpts(mif_hdr_t *
 	int cmptno;
 	mif_cmpt_t **newcmpts;
 	assert(maxcmpts >= hdr->numcmpts);
-	newcmpts = (!hdr->cmpts) ? jas_malloc(maxcmpts * sizeof(mif_cmpt_t *)) :
-	  jas_realloc(hdr->cmpts, maxcmpts * sizeof(mif_cmpt_t *));
+	newcmpts = jas_realloc2(hdr->cmpts, maxcmpts, sizeof(mif_cmpt_t *));
 	if (!newcmpts) {
 		return -1;
 	}
