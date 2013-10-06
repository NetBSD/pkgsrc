$NetBSD: patch-plugins_run-program_plugin.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/run-program/plugin.c.orig	2013-09-29 15:12:54.000000000 +0000
+++ plugins/run-program/plugin.c
@@ -227,7 +227,7 @@ on_run_program_activate (GtkAction* acti
 	{
        gchar *msg = _("The program is already running.\n"
                       	"Do you want to stop it before restarting a new instance?");
-		if (anjuta_util_dialog_boolean_question (GTK_WINDOW ( ANJUTA_PLUGIN (plugin)->shell), TRUE, msg))
+		if (anjuta_util_dialog_boolean_question (GTK_WINDOW ( ANJUTA_PLUGIN (plugin)->shell), TRUE, "%s", msg))
 		{
 			run_plugin_kill_program (plugin, FALSE);
 		}
