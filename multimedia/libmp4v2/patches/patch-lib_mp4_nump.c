$NetBSD: patch-lib_mp4_nump.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/nump.c.orig	2017-09-25 14:55:47.324092855 +0000
+++ lib/mp4/nump.c
@@ -22,27 +22,27 @@
 #include "quicktime.h"
 
 
-int quicktime_nump_init(quicktime_nump_t *nump)
+void quicktime_nump_init(quicktime_nump_t *nump)
 {
 	nump->numPackets = 0;
 }
 
-int quicktime_nump_delete(quicktime_nump_t *nump)
+void quicktime_nump_delete(quicktime_nump_t *nump)
 {
 }
 
-int quicktime_nump_dump(quicktime_nump_t *nump)
+void quicktime_nump_dump(quicktime_nump_t *nump)
 {
 	printf("    total RTP packets\n");
 	printf("     numBytes "U64"\n", nump->numPackets);
 }
 
-int quicktime_read_nump(quicktime_t *file, quicktime_nump_t *nump)
+void quicktime_read_nump(quicktime_t *file, quicktime_nump_t *nump)
 {
 	nump->numPackets = quicktime_read_int64(file);
 }
 
-int quicktime_write_nump(quicktime_t *file, quicktime_nump_t *nump)
+void quicktime_write_nump(quicktime_t *file, quicktime_nump_t *nump)
 {
 	quicktime_atom_t atom;
 
