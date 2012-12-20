$NetBSD: patch-lib_mp4_hintudta.c,v 1.1 2012/12/20 21:44:51 joerg Exp $

--- lib/mp4/hintudta.c.orig	2012-12-20 16:52:58.000000000 +0000
+++ lib/mp4/hintudta.c
@@ -66,7 +66,9 @@ int quicktime_read_hint_udta(quicktime_t
 	} while (quicktime_position(file) < parent_atom->end);
 }
 
-int quicktime_write_hint_udta(quicktime_t *file, quicktime_hint_udta_t *hint_udta)
+void quicktime_write_hint_hnti(quicktime_t *file, quicktime_hint_hnti_t *hnti);
+
+void quicktime_write_hint_udta(quicktime_t *file, quicktime_hint_udta_t *hint_udta)
 {
 	quicktime_atom_t atom;
 
