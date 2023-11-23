$NetBSD: patch-axfer_xfer-libasound.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- axfer/xfer-libasound.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ axfer/xfer-libasound.c
@@ -60,7 +60,7 @@ static const struct option l_opts[] = {
 };
 
 static int xfer_libasound_init(struct xfer_context *xfer,
-			       snd_pcm_stream_t)
+			       snd_pcm_stream_t stream ATTRIBUTE_UNUSED)
 {
 	struct libasound_state *state = xfer->private_data;
 	int err;
@@ -887,7 +887,7 @@ static void xfer_libasound_destroy(struc
 	state->log = NULL;
 }
 
-static void xfer_libasound_help(struct xfer_context *)
+static void xfer_libasound_help(struct xfer_context *xfer ATTRIBUTE_UNUSED)
 {
 	printf(
 "      [BASICS]\n"
