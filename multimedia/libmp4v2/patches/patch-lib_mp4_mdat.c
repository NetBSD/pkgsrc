$NetBSD: patch-lib_mp4_mdat.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/mdat.c.orig	2017-09-25 14:54:53.532822347 +0000
+++ lib/mp4/mdat.c
@@ -1,23 +1,23 @@
 #include "quicktime.h"
 
-int quicktime_mdat_init(quicktime_mdat_t *mdat)
+void quicktime_mdat_init(quicktime_mdat_t *mdat)
 {
 	mdat->size = 8;
 	mdat->start = 0;
 }
 
-int quicktime_mdat_delete(quicktime_mdat_t *mdat)
+void quicktime_mdat_delete(quicktime_mdat_t *mdat)
 {
 }
 
-int quicktime_read_mdat(quicktime_t *file, quicktime_mdat_t *mdat, quicktime_atom_t *parent_atom)
+void quicktime_read_mdat(quicktime_t *file, quicktime_mdat_t *mdat, quicktime_atom_t *parent_atom)
 {
 	mdat->size = parent_atom->size;
 	mdat->start = parent_atom->start;
 	quicktime_atom_skip(file, parent_atom);
 }
 
-int quicktime_write_mdat(quicktime_t *file, quicktime_mdat_t *mdat)
+void quicktime_write_mdat(quicktime_t *file, quicktime_mdat_t *mdat)
 {
 	long position, size = 0, new_size = 0;
 	int i, j;
