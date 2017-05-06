$NetBSD: patch-lib_mp4_sdp.c,v 1.1 2017/05/06 18:12:00 maya Exp $

Fix return type. we're not returning anything.

--- lib/mp4/sdp.c.orig	2001-08-01 00:34:00.000000000 +0000
+++ lib/mp4/sdp.c
@@ -22,12 +22,12 @@
 #include "quicktime.h"
 
 
-int quicktime_sdp_init(quicktime_sdp_t *sdp)
+void quicktime_sdp_init(quicktime_sdp_t *sdp)
 {
         sdp->string = NULL;
 }
 
-int quicktime_sdp_set(quicktime_sdp_t *sdp, char *string)
+void quicktime_sdp_set(quicktime_sdp_t *sdp, char *string)
 {
         free(sdp->string);
         if (string != NULL) {
@@ -38,7 +38,7 @@ int quicktime_sdp_set(quicktime_sdp_t *s
         }
 }
 
-int quicktime_sdp_append(quicktime_sdp_t *sdp, char *appendString)
+void quicktime_sdp_append(quicktime_sdp_t *sdp, char *appendString)
 {
         char* newString = malloc(strlen(sdp->string) + strlen(appendString) + 1);
 
@@ -48,18 +48,18 @@ int quicktime_sdp_append(quicktime_sdp_t
         sdp->string = newString;
 }
 
-int quicktime_sdp_delete(quicktime_sdp_t *sdp)
+void quicktime_sdp_delete(quicktime_sdp_t *sdp)
 {
         free(sdp->string);
 }
 
-int quicktime_sdp_dump(quicktime_sdp_t *sdp)
+void quicktime_sdp_dump(quicktime_sdp_t *sdp)
 {
         printf("    sdp\n");
         printf("     string %s\n", sdp->string);
 }
 
-int quicktime_read_sdp(quicktime_t *file, quicktime_sdp_t *sdp, 
+void quicktime_read_sdp(quicktime_t *file, quicktime_sdp_t *sdp, 
         quicktime_atom_t* sdp_atom)
 {
         int sdpLen = sdp_atom->size - 8;
@@ -69,7 +69,7 @@ int quicktime_read_sdp(quicktime_t *file
         sdp->string[sdpLen] = '\0';
 }
 
-int quicktime_write_sdp(quicktime_t *file, quicktime_sdp_t *sdp)
+void quicktime_write_sdp(quicktime_t *file, quicktime_sdp_t *sdp)
 {
         int i;
         quicktime_atom_t atom;
