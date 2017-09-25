$NetBSD: patch-lib_mp4_gmhd.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/gmhd.c.orig	2017-09-25 14:53:02.313176484 +0000
+++ lib/mp4/gmhd.c
@@ -3,23 +3,23 @@
 
 
 
-int quicktime_gmhd_init(quicktime_gmhd_t *gmhd)
+void quicktime_gmhd_init(quicktime_gmhd_t *gmhd)
 {
 	quicktime_gmin_init(&(gmhd->gmin));
 }
 
-int quicktime_gmhd_delete(quicktime_gmhd_t *gmhd)
+void quicktime_gmhd_delete(quicktime_gmhd_t *gmhd)
 {
 	quicktime_gmin_delete(&(gmhd->gmin));
 }
 
-int quicktime_gmhd_dump(quicktime_gmhd_t *gmhd)
+void quicktime_gmhd_dump(quicktime_gmhd_t *gmhd)
 {
 	printf("    generic media header\n");
 	quicktime_gmin_dump(&gmhd->gmin);
 }
 
-int quicktime_read_gmhd(quicktime_t *file, quicktime_gmhd_t *gmhd, quicktime_atom_t *parent_atom)
+void quicktime_read_gmhd(quicktime_t *file, quicktime_gmhd_t *gmhd, quicktime_atom_t *parent_atom)
 {
 	quicktime_atom_t leaf_atom;
 
@@ -34,7 +34,7 @@ int quicktime_read_gmhd(quicktime_t *fil
 	} while (quicktime_position(file) < parent_atom->end);
 }
 
-int quicktime_write_gmhd(quicktime_t *file, quicktime_gmhd_t *gmhd)
+void quicktime_write_gmhd(quicktime_t *file, quicktime_gmhd_t *gmhd)
 {
 	
 	quicktime_atom_t atom;
