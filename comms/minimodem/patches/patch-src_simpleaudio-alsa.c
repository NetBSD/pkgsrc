$NetBSD: patch-src_simpleaudio-alsa.c,v 1.1 2022/05/07 06:00:17 wiz Exp $

Non-Linux portability.

--- src/simpleaudio-alsa.c.orig	2015-04-22 23:56:58.000000000 +0000
+++ src/simpleaudio-alsa.c
@@ -59,7 +59,11 @@ sa_alsa_read( simpleaudio *sa, void *buf
 	    snd_pcm_prepare(pcm);
 	} else  {
 	    fprintf(stderr, "snd_pcm_readi: %s\n", snd_strerror(r));
+#if defined(ESTRPIPE)
 	    if (r == -EAGAIN || r== -ESTRPIPE)
+#else
+	    if (r == -EAGAIN)
+#endif
 		snd_pcm_wait(pcm, 1000);
 	    else
 		return r;
