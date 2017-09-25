$NetBSD: patch-lib_mp4_tpyl.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/tpyl.c.orig	2017-09-25 14:55:07.879577256 +0000
+++ lib/mp4/tpyl.c
@@ -22,27 +22,27 @@
 #include "quicktime.h"
 
 
-int quicktime_tpyl_init(quicktime_tpyl_t *tpyl)
+void quicktime_tpyl_init(quicktime_tpyl_t *tpyl)
 {
 	tpyl->numBytes = 0;
 }
 
-int quicktime_tpyl_delete(quicktime_tpyl_t *tpyl)
+void quicktime_tpyl_delete(quicktime_tpyl_t *tpyl)
 {
 }
 
-int quicktime_tpyl_dump(quicktime_tpyl_t *tpyl)
+void quicktime_tpyl_dump(quicktime_tpyl_t *tpyl)
 {
 	printf("    total RTP payload bytes\n");
 	printf("     numBytes "U64"\n", tpyl->numBytes);
 }
 
-int quicktime_read_tpyl(quicktime_t *file, quicktime_tpyl_t *tpyl)
+void quicktime_read_tpyl(quicktime_t *file, quicktime_tpyl_t *tpyl)
 {
 	tpyl->numBytes = quicktime_read_int64(file);
 }
 
-int quicktime_write_tpyl(quicktime_t *file, quicktime_tpyl_t *tpyl)
+void quicktime_write_tpyl(quicktime_t *file, quicktime_tpyl_t *tpyl)
 {
 	quicktime_atom_t atom;
 
