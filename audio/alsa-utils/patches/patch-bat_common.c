$NetBSD: patch-bat_common.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- bat/common.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ bat/common.c
@@ -47,7 +47,8 @@ static int update_fmt_to_bat(struct bat 
 }
 
 /* calculate frames and update to bat */
-static int update_frames_to_bat(struct bat *bat, struct wav_chunk_header *header, FILE *)
+static int update_frames_to_bat(struct bat *bat, struct wav_chunk_header *header,
+				FILE *file ATTRIBUTE_UNUSED)
 {
 	/* The number of analyzed captured frames is arbitrarily set to half of
 	   the number of frames of the wav file or the number of frames of the
