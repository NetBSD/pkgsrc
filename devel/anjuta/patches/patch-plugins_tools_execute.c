$NetBSD: patch-plugins_tools_execute.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/tools/execute.c.orig	2013-09-29 15:22:38.000000000 +0000
+++ plugins/tools/execute.c
@@ -562,12 +562,12 @@ atp_output_context_print_result (ATPOutp
 		{
 			if (this == &this->execution->output)
 			{
-				anjuta_util_dialog_info (GTK_WINDOW (this->execution->plugin->shell),
+				anjuta_util_dialog_info (GTK_WINDOW (this->execution->plugin->shell), "%s",
 										 this->buffer->str);
 			}
 			else
 			{
-				anjuta_util_dialog_error (GTK_WINDOW (this->execution->plugin->shell),
+				anjuta_util_dialog_error (GTK_WINDOW (this->execution->plugin->shell), "%s",
 										  this->buffer->str);
 			}
 			g_string_free (this->buffer, TRUE);
