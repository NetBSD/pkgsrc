$NetBSD: patch-lib_mp4_moov.c,v 1.1 2012/12/20 21:44:51 joerg Exp $

--- lib/mp4/moov.c.orig	2012-12-20 16:56:39.000000000 +0000
+++ lib/mp4/moov.c
@@ -91,6 +91,8 @@ int quicktime_read_moov(quicktime_t *fil
 	return 0;
 }
 
+void quicktime_write_udta(quicktime_t *file, quicktime_udta_t *udta);
+
 int quicktime_write_moov(quicktime_t *file, quicktime_moov_t *moov)
 {
 	quicktime_atom_t atom;
