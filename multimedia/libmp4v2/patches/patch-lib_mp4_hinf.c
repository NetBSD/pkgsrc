$NetBSD: patch-lib_mp4_hinf.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/hinf.c.orig	2017-09-25 14:53:28.522486157 +0000
+++ lib/mp4/hinf.c
@@ -22,7 +22,7 @@
 #include "quicktime.h"
 
 
-int quicktime_hinf_init(quicktime_hinf_t *hinf)
+void quicktime_hinf_init(quicktime_hinf_t *hinf)
 {
 	quicktime_trpy_init(&(hinf->trpy));
 	quicktime_nump_init(&(hinf->nump));
@@ -38,7 +38,7 @@ int quicktime_hinf_init(quicktime_hinf_t
 	quicktime_payt_init(&(hinf->payt));
 }
 
-int quicktime_hinf_delete(quicktime_hinf_t *hinf)
+void quicktime_hinf_delete(quicktime_hinf_t *hinf)
 {
 	quicktime_trpy_delete(&(hinf->trpy));
 	quicktime_nump_delete(&(hinf->nump));
@@ -54,7 +54,7 @@ int quicktime_hinf_delete(quicktime_hinf
 	quicktime_payt_delete(&(hinf->payt));
 }
 
-int quicktime_hinf_dump(quicktime_hinf_t *hinf)
+void quicktime_hinf_dump(quicktime_hinf_t *hinf)
 {
 	printf("   hinf\n");
 	quicktime_trpy_dump(&(hinf->trpy));
@@ -71,7 +71,7 @@ int quicktime_hinf_dump(quicktime_hinf_t
 	quicktime_payt_dump(&(hinf->payt));
 }
 
-int quicktime_read_hinf(quicktime_t *file, quicktime_hinf_t *hinf, quicktime_atom_t *parent_atom)
+void quicktime_read_hinf(quicktime_t *file, quicktime_hinf_t *hinf, quicktime_atom_t *parent_atom)
 {
 	quicktime_atom_t leaf_atom;
 
@@ -101,14 +101,14 @@ int quicktime_read_hinf(quicktime_t *fil
 		} else if (quicktime_atom_is(&leaf_atom, "dmax")) {
 			quicktime_read_dmax(file, &(hinf->dmax));
 		} else if (quicktime_atom_is(&leaf_atom, "payt")) {
-			quicktime_read_payt(file, &(hinf->payt), &leaf_atom);
+			quicktime_read_payt(file, &(hinf->payt));
 		} else {
 			quicktime_atom_skip(file, &leaf_atom);
 		}
 	} while (quicktime_position(file) < parent_atom->end);
 }
 
-int quicktime_write_hinf(quicktime_t *file, quicktime_hinf_t *hinf)
+void quicktime_write_hinf(quicktime_t *file, quicktime_hinf_t *hinf)
 {
 	quicktime_atom_t atom;
 
