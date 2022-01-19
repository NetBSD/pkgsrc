$NetBSD: patch-src_otr_otr.c,v 1.1 2022/01/19 22:15:43 nia Exp $

Fix building on Solaris 10
Upstream commit: 58c9aecf86425630f043f554f0d11b625ed88be0
PR pkg/56632

--- src/otr/otr.c.orig	2021-04-08 13:42:24.000000000 +0000
+++ src/otr/otr.c
@@ -643,7 +643,7 @@ static enum otr_msg_status enqueue_otr_f
 		 * Dup the string with enough space for the NULL byte since we are
 		 * about to free it before passing it to the caller.
 		 */
-		*full_msg = strndup(opc->full_msg, opc->msg_len + 1);
+		*full_msg = g_strndup(opc->full_msg, opc->msg_len + 1);
 		/* Reset everything. */
 		free(opc->full_msg);
 		opc->full_msg = NULL;
