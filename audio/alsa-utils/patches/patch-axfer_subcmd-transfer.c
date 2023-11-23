$NetBSD: patch-axfer_subcmd-transfer.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- axfer/subcmd-transfer.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ axfer/subcmd-transfer.c
@@ -40,7 +40,7 @@ static void handle_unix_signal_for_finis
 	ctx_ptr->interrupted = true;
 }
 
-static void handle_unix_signal_for_suspend(int)
+static void handle_unix_signal_for_suspend(int sig ATTRIBUTE_UNUSED)
 {
 	sigset_t curr, prev;
 	struct sigaction sa = {0};
@@ -439,7 +439,7 @@ static int context_process_frames(struct
 }
 
 static void context_post_process(struct context *ctx,
-				 uint64_t)
+				 uint64_t accumulated_frame_count ATTRIBUTE_UNUSED)
 {
 	uint64_t total_frame_count;
 	unsigned int i;
