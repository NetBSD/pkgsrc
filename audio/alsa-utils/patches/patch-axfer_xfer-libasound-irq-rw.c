$NetBSD: patch-axfer_xfer-libasound-irq-rw.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- axfer/xfer-libasound-irq-rw.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ axfer/xfer-libasound-irq-rw.c
@@ -313,7 +313,7 @@ error:
 }
 
 static int w_process_frames_nonblocking(struct libasound_state *state,
-					snd_pcm_state_t,
+					snd_pcm_state_t pcm_state ATTRIBUTE_UNUSED,
 					unsigned int *frame_count,
 					struct mapper_context *mapper,
 					struct container_context *cntrs)
