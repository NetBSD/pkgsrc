$NetBSD: patch-axfer_subcmd-list.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- axfer/subcmd-list.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ axfer/subcmd-list.c
@@ -19,7 +19,7 @@ enum list_op {
 };
 
 static int dump_device(snd_ctl_t *handle, const char *id, const char *name,
-		       snd_pcm_stream_t, snd_pcm_info_t *info)
+		       snd_pcm_stream_t stream ATTRIBUTE_UNUSED, snd_pcm_info_t *info)
 {
 	unsigned int i, count;
 	int err;
