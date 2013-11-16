$NetBSD: patch-src_sound_oss.c,v 1.1 2013/11/16 07:41:02 shattered Exp $

--- src/sound_oss.c.orig	2013-04-06 13:38:02.000000000 +0000
+++ src/sound_oss.c
@@ -109,7 +109,7 @@ static void setaudio(int *rate, int *for
 static int init(struct options *options)
 {
 	char **parm = options->driver_parm;
-	static const char *dev_audio[] = { "/dev/dsp", "/dev/sound/dsp" };
+	static const char *dev_audio[] = { DEVOSSAUDIO, "/dev/sound/dsp" };
 	audio_buf_info info;
 	static char buf[80];
 	int i;
