$NetBSD: patch-src_audio_dma_SDL__dmaaudio.c,v 1.1 2017/10/27 01:28:53 nat Exp $

Enable dma for use with netbsd-8.

DMA parameters must match the hw virtual channel format.
These parameters are controlled by environment variables:
	SDL_DSP_DMA_PRECISION, SDL_DSP_DMA_FREQ and SDL_DSP_DMA_CHANNELS.
I found it also necessary to set SDL_DSP_NOSELECT=1 for playback to work with
dma.
--- src/audio/dma/SDL_dmaaudio.c.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/audio/dma/SDL_dmaaudio.c
@@ -24,6 +24,7 @@
 /* Allow access to a raw mixing buffer */
 
 #include <stdio.h>
+#include <stdbool.h>
 #include <string.h>	/* For strerror() */
 #include <errno.h>
 #include <unistd.h>
@@ -29,6 +31,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <signal.h>
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/ioctl.h>
@@ -311,7 +313,9 @@ static int DMA_OpenAudio(_THIS, SDL_Audi
 	int format;
 	int stereo;
 	int value;
+#if !defined(__NetBSD__) || (__NetBSD_Version__ < 800000000)
 	Uint16 test_format;
+#endif
 	struct audio_buf_info info;
 
 	/* Reset the timer synchronization flag */
@@ -333,6 +337,7 @@ static int DMA_OpenAudio(_THIS, SDL_Audi
 	}
 
 	/* Try for a closest match on audio format */
+#if !defined(__NetBSD__) || (__NetBSD_Version__ < 800000000)
 	format = 0;
 	for ( test_format = SDL_FirstAudioFormat(spec->format);
 						! format && test_format; ) {
@@ -383,6 +388,78 @@ static int DMA_OpenAudio(_THIS, SDL_Audi
 		return(-1);
 	}
 	spec->format = test_format;
+#else
+	char *tmpenv;
+	int prec;
+	bool be = false;
+
+	if (_BYTE_ORDER == _BIG_ENDIAN)
+		be = true;
+	tmpenv = getenv("SDL_DSP_DMA_PRECISION");
+	if (tmpenv == NULL)
+		prec = 0;
+	else
+		prec = atoi(tmpenv);
+	tmpenv = getenv("SDL_DSP_DMA_FREQ");
+	if (tmpenv == NULL)
+		spec->freq = 0;
+	else
+		spec->freq = atoi(tmpenv);
+	tmpenv = getenv("SDL_DSP_DMA_CHANNELS");
+	if (tmpenv == NULL)
+		spec->channels = 0;
+	else
+		spec->channels = atoi(tmpenv);
+	if (prec == 0) {
+		fprintf(stderr, "SDL_DSP_DMA_PRECISION must be set to virtual "
+		    "format precision");
+		return -1;
+	}
+	if (spec->channels == 0) {
+		fprintf(stderr, "SDL_DSP_DMA_CHANNELS must be set to virtual "
+		    "format number of harware channels");
+		return -1;
+	}
+	if (spec->freq == 0) {
+		fprintf(stderr, "SDL_DSP_DMA_FREQ must be set to virtual "
+		    "format frequency");
+		return -1;
+	}
+	switch(prec) {
+	case 8:
+		spec->format = AUDIO_S8;
+		format = AFMT_S8;
+		break;
+#ifdef notyet
+	case 24:
+		if (be) {
+			spec->format = AUDIO_S24MSB;
+			format = AFMT_S24_BE;
+		} else {
+			spec->format = AUDIO_S24LSB;
+			format = AFMT_S24_LE;
+		}
+		break;
+	case 32:
+		if (be) {
+			spec->format = AUDIO_S32MSB;
+			format = AFMT_S32_BE;
+		} else {
+			spec->format = AUDIO_S32LSB;
+			format = AFMT_S32_LE;
+		}
+		break;
+#endif
+	default:
+		if (be) {
+			spec->format = AUDIO_S16MSB;
+			format = AFMT_S16_BE;
+		} else {
+			spec->format = AUDIO_S16LSB;
+			format = AFMT_S16_LE;
+		}
+	}
+#endif
 
 	/* Set the audio format */
 	value = format;
