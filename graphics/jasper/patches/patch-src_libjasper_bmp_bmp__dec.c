$NetBSD: patch-src_libjasper_bmp_bmp__dec.c,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/bmp/bmp_dec.c.orig	2007-01-19 21:43:07.000000000 +0000
+++ src/libjasper/bmp/bmp_dec.c
@@ -283,7 +283,7 @@ static bmp_info_t *bmp_getinfo(jas_strea
 	}
 
 	if (info->numcolors > 0) {
-		if (!(info->palents = jas_malloc(info->numcolors *
+		if (!(info->palents = jas_alloc2(info->numcolors,
 		  sizeof(bmp_palent_t)))) {
 			bmp_info_destroy(info);
 			return 0;
