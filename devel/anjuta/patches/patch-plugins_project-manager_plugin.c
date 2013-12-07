$NetBSD: patch-plugins_project-manager_plugin.c,v 1.2 2013/12/07 23:47:02 dholland Exp $

--- plugins/project-manager/plugin.c.orig	2013-09-13 22:00:36.000000000 +0000
+++ plugins/project-manager/plugin.c
@@ -645,6 +645,8 @@ on_popup_add_source (GtkAction *action, 
 	if (default_source) g_object_unref (default_source);
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 static gboolean
 confirm_removal (ProjectManagerPlugin *plugin, GList *selected)
 {
@@ -757,6 +759,7 @@ confirm_removal (ProjectManagerPlugin *p
 
 	return answer;
 }
+#pragma GCC diagnostic pop
 
 static void
 on_popup_remove (GtkAction *action, ProjectManagerPlugin *plugin)
@@ -1323,7 +1326,7 @@ on_project_loaded (AnjutaPmProject *proj
 		anjuta_shell_present_widget (ANJUTA_PLUGIN (plugin)->shell,
 									plugin->scrolledwindow,
 									NULL);
-		anjuta_status_set_default (status, _("Project"), basename);
+		anjuta_status_set_default (status, _("Project"), "%s", basename);
 		g_free (basename);
 
 		if (plugin->busy)
