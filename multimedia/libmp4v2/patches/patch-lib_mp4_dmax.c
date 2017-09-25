$NetBSD: patch-lib_mp4_dmax.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/dmax.c.orig	2017-09-25 14:52:25.608992194 +0000
+++ lib/mp4/dmax.c
@@ -22,27 +22,27 @@
 #include "quicktime.h"
 
 
-int quicktime_dmax_init(quicktime_dmax_t *dmax)
+void quicktime_dmax_init(quicktime_dmax_t *dmax)
 {
 	dmax->milliSecs = 0;
 }
 
-int quicktime_dmax_delete(quicktime_dmax_t *dmax)
+void quicktime_dmax_delete(quicktime_dmax_t *dmax)
 {
 }
 
-int quicktime_dmax_dump(quicktime_dmax_t *dmax)
+void quicktime_dmax_dump(quicktime_dmax_t *dmax)
 {
 	printf("    max packet duration\n");
-	printf("     milliSecs %lu\n", dmax->milliSecs);
+	printf("     milliSecs %u\n", (unsigned)dmax->milliSecs);
 }
 
-int quicktime_read_dmax(quicktime_t *file, quicktime_dmax_t *dmax)
+void quicktime_read_dmax(quicktime_t *file, quicktime_dmax_t *dmax)
 {
 	dmax->milliSecs = quicktime_read_int32(file);
 }
 
-int quicktime_write_dmax(quicktime_t *file, quicktime_dmax_t *dmax)
+void quicktime_write_dmax(quicktime_t *file, quicktime_dmax_t *dmax)
 {
 	quicktime_atom_t atom;
 
