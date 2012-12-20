$NetBSD: patch-lib_mp4_rtp.c,v 1.1 2012/12/20 21:44:51 joerg Exp $

--- lib/mp4/rtp.c.orig	2012-12-20 16:55:05.000000000 +0000
+++ lib/mp4/rtp.c
@@ -70,7 +70,7 @@ int quicktime_read_rtp(quicktime_t *file
         rtp->string[rtpLen] = '\0';
 }
 
-int quicktime_write_rtp(quicktime_t *file, quicktime_rtp_t *rtp)
+void quicktime_write_rtp(quicktime_t *file, quicktime_rtp_t *rtp)
 {
         int i;
         quicktime_atom_t atom;
