$NetBSD: patch-src_gui-gtk_gtk-utils.c,v 1.1 2015/03/31 15:38:49 joerg Exp $

--- src/gui-gtk/gtk-utils.c.orig	2015-03-26 10:57:34.000000000 +0000
+++ src/gui-gtk/gtk-utils.c
@@ -87,7 +87,7 @@ static void	 invoke_toolbar_button_callb
 						 gpointer user_data);
 static void	 set_toolbar_item_sensitive
 		   (GtkWidget *button,
-		    const GtkUtilsToolbarCallbackArguments *arguments);
+		    GtkUtilsToolbarCallbackArguments *arguments);
 
 static void	 set_widget_sensitivity_on_toggle
 		   (GtkToggleButton *toggle_button, GtkWidget *widget);
@@ -1076,7 +1076,7 @@ gtk_utils_set_toolbar_buttons_sensitive 
 
 static void
 set_toolbar_item_sensitive (GtkWidget *button,
-			    const GtkUtilsToolbarCallbackArguments *arguments)
+			    GtkUtilsToolbarCallbackArguments *arguments)
 {
   const GtkUtilsToolbarEntry *button_entry
     = g_object_get_qdata (G_OBJECT (button), toolbar_button_entry_quark);
