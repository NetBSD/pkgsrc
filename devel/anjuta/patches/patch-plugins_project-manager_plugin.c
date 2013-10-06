$NetBSD: patch-plugins_project-manager_plugin.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/project-manager/plugin.c.orig	2013-09-13 22:00:36.000000000 +0000
+++ plugins/project-manager/plugin.c
@@ -749,9 +749,12 @@ confirm_removal (ProjectManagerPlugin *p
 	else
 		shownMesg = mesg ;
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 	answer =
 		anjuta_util_dialog_boolean_question (get_plugin_parent_window (plugin), FALSE,
 											 shownMesg, _("Confirm remove"));
+#pragma GCC diagnostic pop
 	
 	g_free (shownMesg);
 
@@ -1323,7 +1326,7 @@ on_project_loaded (AnjutaPmProject *proj
 		anjuta_shell_present_widget (ANJUTA_PLUGIN (plugin)->shell,
 									plugin->scrolledwindow,
 									NULL);
-		anjuta_status_set_default (status, _("Project"), basename);
+		anjuta_status_set_default (status, _("Project"), "%s", basename);
 		g_free (basename);
 
 		if (plugin->busy)
