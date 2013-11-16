$NetBSD: patch-src_drivers_netbsd.c,v 1.2 2013/11/16 07:41:02 shattered Exp $

--- src/sound_netbsd.c.orig	2013-04-06 13:38:02.000000000 +0000
+++ src/sound_netbsd.c
@@ -68,21 +68,23 @@ static int init(struct options *options)
 
 	AUDIO_INITINFO(&ainfo);
 
+	ainfo.mode = AUMODE_PLAY_ALL;
 	ainfo.play.sample_rate = options->rate;
 	ainfo.play.channels = options->format & XMP_FORMAT_MONO ? 1 : 2;
 
 	if (options->format & XMP_FORMAT_8BIT) {
 		ainfo.play.precision = 8;
-		ainfo.play.precision = AUDIO_ENCODING_ULINEAR;
+		ainfo.play.encoding = AUDIO_ENCODING_ULINEAR;
 		options->format |= XMP_FORMAT_UNSIGNED;
 	} else {
 		ainfo.play.precision = 16;
-		ainfo.play.precision = AUDIO_ENCODING_SLINEAR;
+		ainfo.play.encoding = AUDIO_ENCODING_SLINEAR;
 		options->format &= ~XMP_FORMAT_UNSIGNED;
 	}
 
 	ainfo.play.gain = gain;
 	ainfo.play.buffer_size = bsize;
+	ainfo.blocksize = 0;
 
 	if (ioctl(audio_fd, AUDIO_SETINFO, &ainfo) == -1) {
 		close(audio_fd);
@@ -99,7 +101,7 @@ static void play(void *b, int i)
 	while (i) {
 		if ((j = write(audio_fd, b, i)) > 0) {
 			i -= j;
-			(char *)b += j;
+			b = (char *)b + j;
 		} else
 			break;
 	}
