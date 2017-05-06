$NetBSD: patch-lib_mp4_hintudta.c,v 1.1 2017/05/06 18:12:00 maya Exp $

Fix return type. we're not returning anything.

--- lib/mp4/hintudta.c.orig	2001-08-01 00:34:00.000000000 +0000
+++ lib/mp4/hintudta.c
@@ -22,26 +22,26 @@
 #include "quicktime.h"
 
 
-int quicktime_hint_udta_init(quicktime_hint_udta_t *hint_udta)
+void quicktime_hint_udta_init(quicktime_hint_udta_t *hint_udta)
 {
 	quicktime_hinf_init(&(hint_udta->hinf));
 	quicktime_hint_hnti_init(&(hint_udta->hnti));
 }
 
-int quicktime_hint_udta_delete(quicktime_hint_udta_t *hint_udta)
+void quicktime_hint_udta_delete(quicktime_hint_udta_t *hint_udta)
 {
 	quicktime_hinf_delete(&(hint_udta->hinf));
 	quicktime_hint_hnti_delete(&(hint_udta->hnti));
 }
 
-int quicktime_hint_udta_dump(quicktime_hint_udta_t *hint_udta)
+void quicktime_hint_udta_dump(quicktime_hint_udta_t *hint_udta)
 {
 	printf("  udta\n");
 	quicktime_hinf_dump(&hint_udta->hinf);
 	quicktime_hint_hnti_dump(&hint_udta->hnti);
 }
 
-int quicktime_read_hint_udta(quicktime_t *file, quicktime_hint_udta_t *hint_udta, quicktime_atom_t *parent_atom)
+void quicktime_read_hint_udta(quicktime_t *file, quicktime_hint_udta_t *hint_udta, quicktime_atom_t *parent_atom)
 {
 	quicktime_atom_t leaf_atom;
 
@@ -66,7 +66,7 @@ int quicktime_read_hint_udta(quicktime_t
 	} while (quicktime_position(file) < parent_atom->end);
 }
 
-int quicktime_write_hint_udta(quicktime_t *file, quicktime_hint_udta_t *hint_udta)
+void quicktime_write_hint_udta(quicktime_t *file, quicktime_hint_udta_t *hint_udta)
 {
 	quicktime_atom_t atom;
 
