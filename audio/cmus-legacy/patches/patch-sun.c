$NetBSD: patch-sun.c,v 1.1 2024/03/16 17:53:11 nia Exp $

Fix building on SunOS.

--- sun.c.orig	2015-06-29 09:56:08.000000000 +0000
+++ sun.c
@@ -31,6 +31,26 @@
 #include "sf.h"
 #include "xmalloc.h"
 
+/* Compatibility defines, for old *BSD or SunOS systems */
+#ifndef AUDIO_ENCODING_SLINEAR_LE
+#define AUDIO_ENCODING_SLINEAR_LE AUDIO_ENCODING_LINEAR
+#endif
+#ifndef AUDIO_ENCODING_SLINEAR_BE
+#define AUDIO_ENCODING_SLINEAR_BE AUDIO_ENCODING_LINEAR
+#endif
+#ifndef AUDIO_ENCODING_ULINEAR_BE
+#define AUDIO_ENCODING_ULINEAR_BE AUDIO_ENCODING_LINEAR
+#endif
+#ifndef AUDIO_ENCODING_ULINEAR_LE
+#define AUDIO_ENCODING_ULINEAR_LE AUDIO_ENCODING_LINEAR
+#endif
+#ifndef AUDIO_ENCODING_SLINEAR
+#define AUDIO_ENCODING_SLINEAR AUDIO_ENCODING_LINEAR8
+#endif
+#ifndef AUDIO_ENCODING_ULINEAR
+#define AUDIO_ENCODING_ULINEAR AUDIO_ENCODING_LINEAR8
+#endif
+
 static sample_format_t sun_sf;
 static int sun_fd = -1;
 
@@ -38,7 +58,11 @@ static char *sun_audio_device = NULL;
 
 static int sun_reset(void)
 {
+#if defined(AUDIO_FLUSH)  /* BSD extension */
 	if (ioctl(sun_fd, AUDIO_FLUSH, NULL) == -1)
+#elif defined(I_FLUSH) && defined(FLUSHW)
+	if (ioctl(sun_fd, I_FLUSH, FLUSHW) == -1)
+#endif
 		return -1;
 
 	return 0;
@@ -56,7 +80,13 @@ static int sun_set_sf(sample_format_t sf
 	ainf.play.channels = sf_get_channels(sun_sf);
 	ainf.play.sample_rate = sf_get_rate(sun_sf);
 	ainf.play.pause = 0;
+#if defined __NetBSD__ || defined __OpenBSD__
+#if defined AUMODE_PLAY_ALL
+	ainf.mode = AUMODE_PLAY | AUMODE_PLAY_ALL;
+#else
 	ainf.mode = AUMODE_PLAY;
+#endif
+#endif
 
 	switch (sf_get_bits(sun_sf)) {
 	case 16:
