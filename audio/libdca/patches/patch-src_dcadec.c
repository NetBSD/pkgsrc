$NetBSD: patch-src_dcadec.c,v 1.1 2018/05/23 17:45:23 adam Exp $

No return statement, since we cannot know whether the return
type is "void" or "int".

Do not print debug info.

--- src/dcadec.c.orig	2018-05-15 13:26:38.000000000 +0000
+++ src/dcadec.c
@@ -66,7 +66,6 @@ static RETSIGTYPE signal_handler (int si
 {
     sigint = 1;
     signal (sig, SIG_DFL);
-    return (RETSIGTYPE)0;
 }
 
 static void print_fps (int final)
@@ -273,7 +272,6 @@ static void dca_decode_data (uint8_t * s
 		length = dca_syncinfo (state, buf, &flags, &sample_rate,
                                        &bit_rate, &frame_length);
 		if (!length) {
-		    fprintf (stderr, "skip\n");
 		    for (bufptr = buf; bufptr < buf + HEADER_SIZE-1; bufptr++)
 			bufptr[0] = bufptr[1];
 		    continue;
