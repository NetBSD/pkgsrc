$NetBSD: patch-plugins_project-wizard_druid.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/project-wizard/druid.c.orig	2013-08-09 00:30:18.000000000 +0000
+++ plugins/project-wizard/druid.c
@@ -157,7 +157,7 @@ npw_druid_set_busy (NPWDruid *druid, gbo
 
 /* Fill dialog page */
 static void
-npw_druid_fill_error_page (NPWDruid* druid, GtkWidget *extra_widget, GtkMessageType type, const gchar *detail, const gchar *mesg,...)
+npw_druid_fill_error_page (NPWDruid* druid, GtkWidget *extra_widget, GtkMessageType type, const gchar *detail, const gchar *mesg,...) G_GNUC_PRINTF(5,6)
 {
 	GtkAssistant *assistant;
 	GtkWidget *page;
