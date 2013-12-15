$NetBSD: patch-src_dialog.c,v 1.1 2013/12/15 19:49:36 joerg Exp $

--- src/dialog.c.orig	2013-12-15 15:25:57.000000000 +0000
+++ src/dialog.c
@@ -25,7 +25,7 @@
 #include "statusbar.h"
 
 gboolean active=FALSE;
-static gchar g_message[1024];
+static gchar my_message[1024];
 
 void center_dialog(GtkWidget *window, GtkWidget *dialog){
 	gint window_x, window_y;
@@ -69,7 +69,7 @@ gboolean idle_warning(gpointer data){
 					GTK_DIALOG_DESTROY_WITH_PARENT /* | GTK_DIALOG_NO_SEPARATOR */,
 					GTK_MESSAGE_WARNING,
 					GTK_BUTTONS_OK,
-					g_message);
+					my_message);
 	gtk_dialog_run(GTK_DIALOG(dialog));
 	gtk_widget_destroy(dialog);
 	active  = FALSE;
@@ -98,7 +98,7 @@ gboolean idle_error(gpointer data){
 					GTK_DIALOG_DESTROY_WITH_PARENT /* | GTK_DIALOG_NO_SEPARATOR */,
 					GTK_MESSAGE_ERROR,
 					GTK_BUTTONS_CLOSE,
-					g_message);
+					my_message);
 					
 	gtk_dialog_run(GTK_DIALOG(dialog));
 	gtk_widget_destroy(dialog);
@@ -114,7 +114,7 @@ void popup_warning(char *message){
 	LOG(LOG_DEBUG, "IN : popup_warning");
 
 	g_idle_add(idle_warning, (gpointer)message);
-	strcpy(g_message, message);
+	strcpy(my_message, message);
 
 	LOG(LOG_DEBUG, "OUT : popup_warning");
 }
@@ -123,7 +123,7 @@ void popup_error(char *message){
 
 	LOG(LOG_DEBUG, "IN : popup_error");
 
-	strcpy(g_message, message);
+	strcpy(my_message, message);
 
 	g_idle_add(idle_error, (gpointer)message);
 
