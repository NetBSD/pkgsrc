$NetBSD: patch-lib_mp4_udta.c,v 1.1 2012/12/20 21:44:51 joerg Exp $

--- lib/mp4/udta.c.orig	2012-12-20 16:53:36.000000000 +0000
+++ lib/mp4/udta.c
@@ -88,7 +88,9 @@ int quicktime_read_udta(quicktime_t *fil
 	return result;
 }
 
-int quicktime_write_udta(quicktime_t *file, quicktime_udta_t *udta)
+void quicktime_write_hnti(quicktime_t *file, quicktime_hnti_t *hnti);
+
+void quicktime_write_udta(quicktime_t *file, quicktime_udta_t *udta)
 {
 	quicktime_atom_t atom, subatom;
 
