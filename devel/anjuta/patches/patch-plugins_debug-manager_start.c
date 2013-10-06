$NetBSD: patch-plugins_debug-manager_start.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/debug-manager/start.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ plugins/debug-manager/start.c
@@ -1392,7 +1392,7 @@ dma_quit_debugger (DmaStart* this)
         gchar *msg = _("The program is already running.\n"
                       	"Do you still want to stop the debugger?");
 		
-		if (!anjuta_util_dialog_boolean_question (GTK_WINDOW (this->plugin->shell), TRUE, msg)) return FALSE;
+		if (!anjuta_util_dialog_boolean_question (GTK_WINDOW (this->plugin->shell), TRUE, "%s", msg)) return FALSE;
 	}
 	
 	dma_queue_interrupt (this->debugger);
