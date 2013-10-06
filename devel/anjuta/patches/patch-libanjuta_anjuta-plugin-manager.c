$NetBSD: patch-libanjuta_anjuta-plugin-manager.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- libanjuta/anjuta-plugin-manager.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ libanjuta/anjuta-plugin-manager.c
@@ -749,7 +749,7 @@ plugin_set_update (AnjutaPluginManager *
 							"error message leading to this was:\n%s"), 
 														  anjuta_plugin_handle_get_name (selected_plugin),
 														  error->message);
-						anjuta_util_dialog_error (GTK_WINDOW(plugin_manager->priv->shell),
+						anjuta_util_dialog_error (GTK_WINDOW(plugin_manager->priv->shell), "%s",
 												  message);
 						g_error_free (error);
 						g_free(message);
