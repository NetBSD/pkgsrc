$NetBSD: patch-lib_mp4_tmin.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/tmin.c.orig	2017-09-25 14:55:09.903663456 +0000
+++ lib/mp4/tmin.c
@@ -22,27 +22,27 @@
 #include "quicktime.h"
 
 
-int quicktime_tmin_init(quicktime_tmin_t *tmin)
+void quicktime_tmin_init(quicktime_tmin_t *tmin)
 {
 	tmin->milliSecs = 0;
 }
 
-int quicktime_tmin_delete(quicktime_tmin_t *tmin)
+void quicktime_tmin_delete(quicktime_tmin_t *tmin)
 {
 }
 
-int quicktime_tmin_dump(quicktime_tmin_t *tmin)
+void quicktime_tmin_dump(quicktime_tmin_t *tmin)
 {
 	printf("    min relative xmit time\n");
-	printf("     milliSecs %lu\n", tmin->milliSecs);
+	printf("     milliSecs %u\n", (unsigned)tmin->milliSecs);
 }
 
-int quicktime_read_tmin(quicktime_t *file, quicktime_tmin_t *tmin)
+void quicktime_read_tmin(quicktime_t *file, quicktime_tmin_t *tmin)
 {
 	tmin->milliSecs = quicktime_read_int32(file);
 }
 
-int quicktime_write_tmin(quicktime_t *file, quicktime_tmin_t *tmin)
+void quicktime_write_tmin(quicktime_t *file, quicktime_tmin_t *tmin)
 {
 	quicktime_atom_t atom;
 
