$NetBSD: patch-plugins_build-basic-autotools_executer.c,v 1.2 2013/12/07 23:47:02 dholland Exp $

--- plugins/build-basic-autotools/executer.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ plugins/build-basic-autotools/executer.c
@@ -205,6 +205,9 @@ get_program_parameters (BasicAutotoolsPl
 	return success;
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
+
 void
 execute_program (BasicAutotoolsPlugin* plugin, const gchar *pre_select_uri)
 {
@@ -375,7 +378,6 @@ execute_program (BasicAutotoolsPlugin* p
 			if (plugin->commands[IANJUTA_BUILDABLE_COMMAND_EXECUTE])
 			{
 				gchar *oldcmd = cmd;
-
 				cmd = g_strdup_printf (plugin->commands[IANJUTA_BUILDABLE_COMMAND_EXECUTE],
 					oldcmd);
 
@@ -416,3 +418,4 @@ execute_program (BasicAutotoolsPlugin* p
 	g_free (target);
 	g_free (args);
 }
+#pragma GCC diagnostic pop
