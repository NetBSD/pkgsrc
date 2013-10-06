$NetBSD: patch-plugins_gdb_debugger.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/gdb/debugger.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ plugins/gdb/debugger.c
@@ -2084,10 +2084,8 @@ debugger_is_connected (Debugger *debugge
 	
 		/* The %s argument is an error message returned by gdb.
 		 * It is something like, "No such file or directory" */
-		msg = g_strdup_printf(_("Unable to connect to remote target, %s\nDo you want to try again?"),
+		retry = anjuta_util_dialog_boolean_question (debugger->priv->parent_win, FALSE, _("Unable to connect to remote target, %s\nDo you want to try again?"),
 							  error->message);
-		retry = anjuta_util_dialog_boolean_question (debugger->priv->parent_win, FALSE, msg);
-		g_free (msg);
 		if (retry)
 		{
 			gchar *cmd;
