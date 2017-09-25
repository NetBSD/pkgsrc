$NetBSD: patch-lib_mp4_payt.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/payt.c.orig	2017-09-25 14:55:45.324938288 +0000
+++ lib/mp4/payt.c
@@ -22,30 +22,30 @@
 #include "quicktime.h"
 
 
-int quicktime_payt_init(quicktime_payt_t *payt)
+void quicktime_payt_init(quicktime_payt_t *payt)
 {
 	payt->payloadNumber = 0;
 	payt->rtpMapString[0] = '\0';
 }
 
-int quicktime_payt_delete(quicktime_payt_t *payt)
+void quicktime_payt_delete(quicktime_payt_t *payt)
 {
 }
 
-int quicktime_payt_dump(quicktime_payt_t *payt)
+void quicktime_payt_dump(quicktime_payt_t *payt)
 {
 	printf("    payload type\n");
-	printf("     payload number %lu\n", payt->payloadNumber);
+	printf("     payload number %u\n", (unsigned)payt->payloadNumber);
 	printf("     rtp map string %s\n", payt->rtpMapString);
 }
 
-int quicktime_read_payt(quicktime_t *file, quicktime_payt_t *payt)
+void quicktime_read_payt(quicktime_t *file, quicktime_payt_t *payt)
 {
 	payt->payloadNumber = quicktime_read_int32(file);
 	quicktime_read_pascal(file, payt->rtpMapString);
 }
 
-int quicktime_write_payt(quicktime_t *file, quicktime_payt_t *payt)
+void quicktime_write_payt(quicktime_t *file, quicktime_payt_t *payt)
 {
 	quicktime_atom_t atom;
 
