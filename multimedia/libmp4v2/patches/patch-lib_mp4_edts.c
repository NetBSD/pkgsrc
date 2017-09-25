$NetBSD: patch-lib_mp4_edts.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/edts.c.orig	2017-09-25 14:51:41.535806446 +0000
+++ lib/mp4/edts.c
@@ -1,21 +1,21 @@
 #include "quicktime.h"
 
-int quicktime_edts_init(quicktime_edts_t *edts)
+void quicktime_edts_init(quicktime_edts_t *edts)
 {
 	quicktime_elst_init(&(edts->elst));
 }
 
-int quicktime_edts_delete(quicktime_edts_t *edts)
+void quicktime_edts_delete(quicktime_edts_t *edts)
 {
 	quicktime_elst_delete(&(edts->elst));
 }
 
-int quicktime_edts_init_table(quicktime_edts_t *edts)
+void quicktime_edts_init_table(quicktime_edts_t *edts)
 {
 	quicktime_elst_init_all(&(edts->elst));
 }
 
-int quicktime_read_edts(quicktime_t *file, quicktime_edts_t *edts, quicktime_atom_t *edts_atom)
+void quicktime_read_edts(quicktime_t *file, quicktime_edts_t *edts, quicktime_atom_t *edts_atom)
 {
 	quicktime_atom_t leaf_atom;
 
@@ -29,13 +29,13 @@ int quicktime_read_edts(quicktime_t *fil
 	}while(quicktime_position(file) < edts_atom->end);
 }
 
-int quicktime_edts_dump(quicktime_edts_t *edts)
+void quicktime_edts_dump(quicktime_edts_t *edts)
 {
 	printf("  edit atom (edts)\n");
 	quicktime_elst_dump(&(edts->elst));
 }
 
-int quicktime_write_edts(quicktime_t *file, quicktime_edts_t *edts, long duration)
+void quicktime_write_edts(quicktime_t *file, quicktime_edts_t *edts, long duration)
 {
 	quicktime_atom_t atom;
 	quicktime_atom_write_header(file, &atom, "edts");
