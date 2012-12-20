$NetBSD: patch-lib_mp4_sdp.c,v 1.1 2012/12/20 21:44:51 joerg Exp $

--- lib/mp4/sdp.c.orig	2012-12-20 16:55:33.000000000 +0000
+++ lib/mp4/sdp.c
@@ -69,7 +69,7 @@ int quicktime_read_sdp(quicktime_t *file
         sdp->string[sdpLen] = '\0';
 }
 
-int quicktime_write_sdp(quicktime_t *file, quicktime_sdp_t *sdp)
+void quicktime_write_sdp(quicktime_t *file, quicktime_sdp_t *sdp)
 {
         int i;
         quicktime_atom_t atom;
