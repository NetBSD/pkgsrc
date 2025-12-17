$NetBSD: patch-pcm__sndio.c,v 1.1 2025/12/17 16:33:11 vins Exp $

Replace EBADFD with EBADF, for portability reasons.

--- pcm_sndio.c.orig	2025-12-17 17:24:54.479871178 +0000
+++ pcm_sndio.c
@@ -141,7 +141,7 @@ sndio_prepare(snd_pcm_ioplug_t *io)
 
 	if (sio_start(sndio->hdl) == 0) {
 		if (sio_eof(sndio->hdl) == 1)
-			return -EBADFD;
+			return -EBADF;
 		return -EAGAIN;
 	}
 	sndio->started = 1;
