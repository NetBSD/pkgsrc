$NetBSD: patch-plugins_build-basic-autotools_executer.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/build-basic-autotools/executer.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ plugins/build-basic-autotools/executer.c
@@ -375,9 +375,11 @@ execute_program (BasicAutotoolsPlugin* p
 			if (plugin->commands[IANJUTA_BUILDABLE_COMMAND_EXECUTE])
 			{
 				gchar *oldcmd = cmd;
-
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 				cmd = g_strdup_printf (plugin->commands[IANJUTA_BUILDABLE_COMMAND_EXECUTE],
 					oldcmd);
+#pragma GCC diagnostic pop
 
 				g_free (oldcmd);
 			} else {
