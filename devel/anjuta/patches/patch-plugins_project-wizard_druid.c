$NetBSD: patch-plugins_project-wizard_druid.c,v 1.2 2013/12/07 23:47:02 dholland Exp $

--- plugins/project-wizard/druid.c.orig	2013-08-09 00:30:18.000000000 +0000
+++ plugins/project-wizard/druid.c
@@ -156,7 +156,7 @@ npw_druid_set_busy (NPWDruid *druid, gbo
  *---------------------------------------------------------------------------*/
 
 /* Fill dialog page */
-static void
+static G_GNUC_PRINTF(5,6) void
 npw_druid_fill_error_page (NPWDruid* druid, GtkWidget *extra_widget, GtkMessageType type, const gchar *detail, const gchar *mesg,...)
 {
 	GtkAssistant *assistant;
