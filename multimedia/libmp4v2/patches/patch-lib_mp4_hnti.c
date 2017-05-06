$NetBSD: patch-lib_mp4_hnti.c,v 1.1 2017/05/06 18:12:00 maya Exp $

Fix return type. we're not returning anything.

--- lib/mp4/hnti.c.orig	2001-08-30 16:23:13.000000000 +0000
+++ lib/mp4/hnti.c
@@ -22,23 +22,23 @@
 #include "quicktime.h"
 
 
-int quicktime_hnti_init(quicktime_hnti_t *hnti)
+void quicktime_hnti_init(quicktime_hnti_t *hnti)
 {
 	quicktime_rtp_init(&(hnti->rtp));
 }
 
-int quicktime_hnti_delete(quicktime_hnti_t *hnti)
+void quicktime_hnti_delete(quicktime_hnti_t *hnti)
 {
 	quicktime_rtp_delete(&(hnti->rtp));
 }
 
-int quicktime_hnti_dump(quicktime_hnti_t *hnti)
+void quicktime_hnti_dump(quicktime_hnti_t *hnti)
 {
 	printf("   hnti\n");
 	quicktime_rtp_dump(&hnti->rtp);
 }
 
-int quicktime_read_hnti(quicktime_t *file, quicktime_hnti_t *hnti, quicktime_atom_t *parent_atom)
+void quicktime_read_hnti(quicktime_t *file, quicktime_hnti_t *hnti, quicktime_atom_t *parent_atom)
 {
 	quicktime_atom_t leaf_atom;
 
@@ -53,7 +53,7 @@ int quicktime_read_hnti(quicktime_t *fil
 	} while (quicktime_position(file) < parent_atom->end);
 }
 
-int quicktime_write_hnti(quicktime_t *file, quicktime_hnti_t *hnti)
+void quicktime_write_hnti(quicktime_t *file, quicktime_hnti_t *hnti)
 {
 	quicktime_atom_t atom;
 
