$NetBSD: patch-plugins_cvs-plugin_cvs-interface.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/cvs-plugin/cvs-interface.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ plugins/cvs-plugin/cvs-interface.c
@@ -58,8 +58,11 @@ static gchar* create_cvs_command_with_cv
 	{
 		cvsroot = "";
 	}
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 	command = g_strdup_printf(CVS_FORMAT, cvs, global_options, cvsroot, action,  
 								command_options, command_arguments);
+#pragma GCC diagnostic pop
 	g_free (cvs);
 	g_free (global_options);
 	
