$NetBSD: patch-lib_mp4_tmax.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/tmax.c.orig	2017-09-25 14:55:12.027621878 +0000
+++ lib/mp4/tmax.c
@@ -22,27 +22,27 @@
 #include "quicktime.h"
 
 
-int quicktime_tmax_init(quicktime_tmax_t *tmax)
+void quicktime_tmax_init(quicktime_tmax_t *tmax)
 {
 	tmax->milliSecs = 0;
 }
 
-int quicktime_tmax_delete(quicktime_tmax_t *tmax)
+void quicktime_tmax_delete(quicktime_tmax_t *tmax)
 {
 }
 
-int quicktime_tmax_dump(quicktime_tmax_t *tmax)
+void quicktime_tmax_dump(quicktime_tmax_t *tmax)
 {
 	printf("    max relative xmit time\n");
-	printf("     milliSecs %lu\n", tmax->milliSecs);
+	printf("     milliSecs %u\n", (unsigned)tmax->milliSecs);
 }
 
-int quicktime_read_tmax(quicktime_t *file, quicktime_tmax_t *tmax)
+void quicktime_read_tmax(quicktime_t *file, quicktime_tmax_t *tmax)
 {
 	tmax->milliSecs = quicktime_read_int32(file);
 }
 
-int quicktime_write_tmax(quicktime_t *file, quicktime_tmax_t *tmax)
+void quicktime_write_tmax(quicktime_t *file, quicktime_tmax_t *tmax)
 {
 	quicktime_atom_t atom;
 
