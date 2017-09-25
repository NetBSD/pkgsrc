$NetBSD: patch-lib_mp4_dimm.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/dimm.c.orig	2017-09-25 14:47:23.811471892 +0000
+++ lib/mp4/dimm.c
@@ -22,27 +22,27 @@
 #include "quicktime.h"
 
 
-int quicktime_dimm_init(quicktime_dimm_t *dimm)
+void quicktime_dimm_init(quicktime_dimm_t *dimm)
 {
 	dimm->numBytes = 0;
 }
 
-int quicktime_dimm_delete(quicktime_dimm_t *dimm)
+void quicktime_dimm_delete(quicktime_dimm_t *dimm)
 {
 }
 
-int quicktime_dimm_dump(quicktime_dimm_t *dimm)
+void quicktime_dimm_dump(quicktime_dimm_t *dimm)
 {
 	printf("    total immediate bytes\n");
 	printf("     numBytes "U64"\n", dimm->numBytes);
 }
 
-int quicktime_read_dimm(quicktime_t *file, quicktime_dimm_t *dimm)
+void quicktime_read_dimm(quicktime_t *file, quicktime_dimm_t *dimm)
 {
 	dimm->numBytes = quicktime_read_int64(file);
 }
 
-int quicktime_write_dimm(quicktime_t *file, quicktime_dimm_t *dimm)
+void quicktime_write_dimm(quicktime_t *file, quicktime_dimm_t *dimm)
 {
 	quicktime_atom_t atom;
 
