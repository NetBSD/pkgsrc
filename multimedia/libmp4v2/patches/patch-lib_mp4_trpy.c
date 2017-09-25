$NetBSD: patch-lib_mp4_trpy.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/trpy.c.orig	2017-09-25 14:55:03.530480720 +0000
+++ lib/mp4/trpy.c
@@ -22,27 +22,27 @@
 #include "quicktime.h"
 
 
-int quicktime_trpy_init(quicktime_trpy_t *trpy)
+void quicktime_trpy_init(quicktime_trpy_t *trpy)
 {
 	trpy->numBytes = 0;
 }
 
-int quicktime_trpy_delete(quicktime_trpy_t *trpy)
+void quicktime_trpy_delete(quicktime_trpy_t *trpy)
 {
 }
 
-int quicktime_trpy_dump(quicktime_trpy_t *trpy)
+void quicktime_trpy_dump(quicktime_trpy_t *trpy)
 {
 	printf("    total RTP bytes\n");
 	printf("     numBytes "U64"\n", trpy->numBytes);
 }
 
-int quicktime_read_trpy(quicktime_t *file, quicktime_trpy_t *trpy)
+void quicktime_read_trpy(quicktime_t *file, quicktime_trpy_t *trpy)
 {
 	trpy->numBytes = quicktime_read_int64(file);
 }
 
-int quicktime_write_trpy(quicktime_t *file, quicktime_trpy_t *trpy)
+void quicktime_write_trpy(quicktime_t *file, quicktime_trpy_t *trpy)
 {
 	quicktime_atom_t atom;
 
