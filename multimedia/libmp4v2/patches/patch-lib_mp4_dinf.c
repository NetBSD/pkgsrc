$NetBSD: patch-lib_mp4_dinf.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/dinf.c.orig	2017-09-25 14:47:48.241855167 +0000
+++ lib/mp4/dinf.c
@@ -1,27 +1,27 @@
 #include "quicktime.h"
 
-int quicktime_dinf_init(quicktime_dinf_t *dinf)
+void quicktime_dinf_init(quicktime_dinf_t *dinf)
 {
 	quicktime_dref_init(&(dinf->dref));
 }
 
-int quicktime_dinf_delete(quicktime_dinf_t *dinf)
+void quicktime_dinf_delete(quicktime_dinf_t *dinf)
 {
 	quicktime_dref_delete(&(dinf->dref));
 }
 
-int quicktime_dinf_init_all(quicktime_dinf_t *dinf)
+void quicktime_dinf_init_all(quicktime_dinf_t *dinf)
 {
 	quicktime_dref_init_all(&(dinf->dref));
 }
 
-int quicktime_dinf_dump(quicktime_dinf_t *dinf)
+void quicktime_dinf_dump(quicktime_dinf_t *dinf)
 {
 	printf("    data information (dinf)\n");
 	quicktime_dref_dump(&(dinf->dref));
 }
 
-int quicktime_read_dinf(quicktime_t *file, quicktime_dinf_t *dinf, quicktime_atom_t *dinf_atom)
+void quicktime_read_dinf(quicktime_t *file, quicktime_dinf_t *dinf, quicktime_atom_t *dinf_atom)
 {
 	quicktime_atom_t leaf_atom;
 
@@ -35,7 +35,7 @@ int quicktime_read_dinf(quicktime_t *fil
 	}while(quicktime_position(file) < dinf_atom->end);
 }
 
-int quicktime_write_dinf(quicktime_t *file, quicktime_dinf_t *dinf)
+void quicktime_write_dinf(quicktime_t *file, quicktime_dinf_t *dinf)
 {
 	quicktime_atom_t atom;
 	quicktime_atom_write_header(file, &atom, "dinf");
