$NetBSD: patch-lib_mp4_pmax.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/pmax.c.orig	2017-09-25 14:55:43.236863278 +0000
+++ lib/mp4/pmax.c
@@ -22,27 +22,27 @@
 #include "quicktime.h"
 
 
-int quicktime_pmax_init(quicktime_pmax_t *pmax)
+void quicktime_pmax_init(quicktime_pmax_t *pmax)
 {
 	pmax->numBytes = 0;
 }
 
-int quicktime_pmax_delete(quicktime_pmax_t *pmax)
+void quicktime_pmax_delete(quicktime_pmax_t *pmax)
 {
 }
 
-int quicktime_pmax_dump(quicktime_pmax_t *pmax)
+void quicktime_pmax_dump(quicktime_pmax_t *pmax)
 {
 	printf("    max packet size\n");
-	printf("     numBytes %lu\n", pmax->numBytes);
+	printf("     numBytes %u\n", (unsigned)pmax->numBytes);
 }
 
-int quicktime_read_pmax(quicktime_t *file, quicktime_pmax_t *pmax)
+void quicktime_read_pmax(quicktime_t *file, quicktime_pmax_t *pmax)
 {
 	pmax->numBytes = quicktime_read_int32(file);
 }
 
-int quicktime_write_pmax(quicktime_t *file, quicktime_pmax_t *pmax)
+void quicktime_write_pmax(quicktime_t *file, quicktime_pmax_t *pmax)
 {
 	quicktime_atom_t atom;
 
