$NetBSD: patch-src_opusdec.c,v 1.1 2020/04/20 17:39:13 nia Exp $

Fix compilation on NetBSD/SunOS.

--- src/opusdec.c.orig	2018-09-15 06:04:51.000000000 +0000
+++ src/opusdec.c
@@ -373,7 +373,7 @@ FILE *out_file_open(char *outFile, int f
 # endif
       info.play.encoding = AUDIO_ENCODING_SLINEAR;
       info.play.precision = 16;
-      info.play.input_sample_rate = rate;
+      info.play.sample_rate = rate;
       info.play.channels = *channels;
 
       if (ioctl(audio_fd, AUDIO_SETINFO, &info) < 0)
