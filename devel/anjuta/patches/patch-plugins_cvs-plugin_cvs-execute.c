$NetBSD: patch-plugins_cvs-plugin_cvs-execute.c,v 1.1.2.2 2016/05/11 15:33:29 bsiegert Exp $

--- plugins/cvs-plugin/cvs-execute.c.orig	2016-05-06 12:59:57.000000000 +0000
+++ plugins/cvs-plugin/cvs-execute.c
@@ -218,8 +218,7 @@ cvs_execute_common (CVSPlugin* plugin, c
 	if (plugin->executing_command)
 	{
 		anjuta_util_dialog_error
-			(NULL,_("CVS command is running — please wait until it finishes!"),
-			 NULL);
+			(NULL,_("CVS command is running — please wait until it finishes!"));
 		return;
 	}
 		
