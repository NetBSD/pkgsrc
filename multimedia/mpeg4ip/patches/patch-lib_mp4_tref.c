$NetBSD: patch-lib_mp4_tref.c,v 1.1 2012/12/20 21:44:51 joerg Exp $

--- lib/mp4/tref.c.orig	2012-12-20 16:56:13.000000000 +0000
+++ lib/mp4/tref.c
@@ -58,7 +58,7 @@ int quicktime_read_tref(quicktime_t *fil
 	} while (quicktime_position(file) < parent_atom->end);
 }
 
-int quicktime_write_tref(quicktime_t *file, quicktime_tref_t *tref)
+void quicktime_write_tref(quicktime_t *file, quicktime_tref_t *tref)
 {
 	quicktime_atom_t atom;
 
