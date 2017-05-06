$NetBSD: patch-lib_mp4_tref.c,v 1.1 2017/05/06 18:12:00 maya Exp $

Fix return type. we're not returning anything.

--- lib/mp4/tref.c.orig	2001-08-01 00:34:00.000000000 +0000
+++ lib/mp4/tref.c
@@ -22,28 +22,28 @@
 #include "quicktime.h"
 
 
-int quicktime_tref_init(quicktime_tref_t *tref)
+void quicktime_tref_init(quicktime_tref_t *tref)
 {
 	quicktime_hint_init(&(tref->hint));
 }
 
-int quicktime_tref_init_hint(quicktime_tref_t *tref, quicktime_trak_t *refTrak)
+void quicktime_tref_init_hint(quicktime_tref_t *tref, quicktime_trak_t *refTrak)
 {
 	quicktime_hint_set(&(tref->hint), refTrak);
 }
 
-int quicktime_tref_delete(quicktime_tref_t *tref)
+void quicktime_tref_delete(quicktime_tref_t *tref)
 {
 	quicktime_hint_delete(&(tref->hint));
 }
 
-int quicktime_tref_dump(quicktime_tref_t *tref)
+void quicktime_tref_dump(quicktime_tref_t *tref)
 {
 	printf("  tref\n");
 	quicktime_hint_dump(&tref->hint);
 }
 
-int quicktime_read_tref(quicktime_t *file, quicktime_tref_t *tref, quicktime_atom_t *parent_atom)
+void quicktime_read_tref(quicktime_t *file, quicktime_tref_t *tref, quicktime_atom_t *parent_atom)
 {
 	quicktime_atom_t leaf_atom;
 
@@ -58,7 +58,7 @@ int quicktime_read_tref(quicktime_t *fil
 	} while (quicktime_position(file) < parent_atom->end);
 }
 
-int quicktime_write_tref(quicktime_t *file, quicktime_tref_t *tref)
+void quicktime_write_tref(quicktime_t *file, quicktime_tref_t *tref)
 {
 	quicktime_atom_t atom;
 
