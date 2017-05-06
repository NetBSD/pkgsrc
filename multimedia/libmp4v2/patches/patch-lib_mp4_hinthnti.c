$NetBSD: patch-lib_mp4_hinthnti.c,v 1.1 2017/05/06 18:12:00 maya Exp $

Fix return type. we're not returning anything.

--- lib/mp4/hinthnti.c.orig	2001-08-01 00:34:00.000000000 +0000
+++ lib/mp4/hinthnti.c
@@ -22,23 +22,23 @@
 #include "quicktime.h"
 
 
-int quicktime_hint_hnti_init(quicktime_hint_hnti_t *hnti)
+void quicktime_hint_hnti_init(quicktime_hint_hnti_t *hnti)
 {
 	quicktime_sdp_init(&(hnti->sdp));
 }
 
-int quicktime_hint_hnti_delete(quicktime_hint_hnti_t *hnti)
+void quicktime_hint_hnti_delete(quicktime_hint_hnti_t *hnti)
 {
 	quicktime_sdp_delete(&(hnti->sdp));
 }
 
-int quicktime_hint_hnti_dump(quicktime_hint_hnti_t *hnti)
+void quicktime_hint_hnti_dump(quicktime_hint_hnti_t *hnti)
 {
 	printf("   hnti\n");
 	quicktime_sdp_dump(&hnti->sdp);
 }
 
-int quicktime_read_hint_hnti(quicktime_t *file, quicktime_hint_hnti_t *hnti, quicktime_atom_t *parent_atom)
+void quicktime_read_hint_hnti(quicktime_t *file, quicktime_hint_hnti_t *hnti, quicktime_atom_t *parent_atom)
 {
 	quicktime_atom_t leaf_atom;
 
@@ -53,7 +53,7 @@ int quicktime_read_hint_hnti(quicktime_t
 	} while (quicktime_position(file) < parent_atom->end);
 }
 
-int quicktime_write_hint_hnti(quicktime_t *file, quicktime_hint_hnti_t *hnti)
+void quicktime_write_hint_hnti(quicktime_t *file, quicktime_hint_hnti_t *hnti)
 {
 	quicktime_atom_t atom;
 
