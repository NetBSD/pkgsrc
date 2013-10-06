$NetBSD: patch-plugins_debug-manager_queue.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/debug-manager/queue.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ plugins/debug-manager/queue.c
@@ -419,7 +419,7 @@ dma_debugger_queue_execute (DmaDebuggerQ
 			{
 				if (err->message != NULL)
 				{
-					anjuta_util_dialog_error (GTK_WINDOW (ANJUTA_PLUGIN (self->plugin)->shell), err->message);
+					anjuta_util_dialog_error (GTK_WINDOW (ANJUTA_PLUGIN (self->plugin)->shell), "%s", err->message);
 				}
 			
 				g_error_free (err);
