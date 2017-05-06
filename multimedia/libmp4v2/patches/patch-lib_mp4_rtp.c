$NetBSD: patch-lib_mp4_rtp.c,v 1.1 2017/05/06 18:12:00 maya Exp $

Fix return type. we're not returning anything.

--- lib/mp4/rtp.c.orig	2001-08-30 16:23:13.000000000 +0000
+++ lib/mp4/rtp.c
@@ -22,12 +22,12 @@
 #include "quicktime.h"
 
 
-int quicktime_rtp_init(quicktime_rtp_t *rtp)
+void quicktime_rtp_init(quicktime_rtp_t *rtp)
 {
         rtp->string = NULL;
 }
 
-int quicktime_rtp_set(quicktime_rtp_t *rtp, char *string)
+void quicktime_rtp_set(quicktime_rtp_t *rtp, char *string)
 {
         free(rtp->string);
         if (string != NULL) {
@@ -38,7 +38,7 @@ int quicktime_rtp_set(quicktime_rtp_t *r
         }
 }
 
-int quicktime_rtp_append(quicktime_rtp_t *rtp, char *appendString)
+void quicktime_rtp_append(quicktime_rtp_t *rtp, char *appendString)
 {
         char* newString = malloc(strlen(rtp->string) + strlen(appendString) + 1);
 
@@ -48,18 +48,18 @@ int quicktime_rtp_append(quicktime_rtp_t
         rtp->string = newString;
 }
 
-int quicktime_rtp_delete(quicktime_rtp_t *rtp)
+void quicktime_rtp_delete(quicktime_rtp_t *rtp)
 {
         free(rtp->string);
 }
 
-int quicktime_rtp_dump(quicktime_rtp_t *rtp)
+void quicktime_rtp_dump(quicktime_rtp_t *rtp)
 {
         printf("    rtp\n");
         printf("     string %s\n", rtp->string);
 }
 
-int quicktime_read_rtp(quicktime_t *file, quicktime_rtp_t *rtp, 
+void quicktime_read_rtp(quicktime_t *file, quicktime_rtp_t *rtp, 
         quicktime_atom_t* rtp_atom)
 {
         int rtpLen = rtp_atom->size - 12;
@@ -70,7 +70,7 @@ int quicktime_read_rtp(quicktime_t *file
         rtp->string[rtpLen] = '\0';
 }
 
-int quicktime_write_rtp(quicktime_t *file, quicktime_rtp_t *rtp)
+void quicktime_write_rtp(quicktime_t *file, quicktime_rtp_t *rtp)
 {
         int i;
         quicktime_atom_t atom;
