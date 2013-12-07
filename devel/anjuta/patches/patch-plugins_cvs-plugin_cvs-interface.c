$NetBSD: patch-plugins_cvs-plugin_cvs-interface.c,v 1.2 2013/12/07 23:47:02 dholland Exp $

--- plugins/cvs-plugin/cvs-interface.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ plugins/cvs-plugin/cvs-interface.c
@@ -24,6 +24,8 @@
 #include "plugin.h"
 #include "libgen.h"
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 static gchar* create_cvs_command_with_cvsroot(GSettings* settings,
 								const gchar* action, 
 								const gchar* command_options,
@@ -65,6 +67,7 @@ static gchar* create_cvs_command_with_cv
 	
 	return command;
 }
+#pragma GCC diagnostic pop
 
 inline static gchar* create_cvs_command(GSettings* settings,
 								const gchar* action, 
