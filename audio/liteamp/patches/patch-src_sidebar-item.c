$NetBSD: patch-src_sidebar-item.c,v 1.1 2012/07/03 18:20:29 joerg Exp $

--- src/sidebar-item.c.orig	2012-07-03 15:26:52.000000000 +0000
+++ src/sidebar-item.c
@@ -80,7 +80,7 @@ GtkWidget* sidebar_item_new(gchar* title
         
     item->filename = (filename && filename[0])
             ? g_strdup(filename)
-            : g_strdup_printf("%s/.liteamp/%08x-%08x.pls", g_get_home_dir(), time(NULL), clock());
+            : g_strdup_printf("%s/.liteamp/%08llx-%08x.pls", g_get_home_dir(), (long long)time(NULL), clock());
 
     gtk_button_set_relief(GTK_BUTTON(item), GTK_RELIEF_NONE);
     gtk_toggle_button_set_mode(GTK_TOGGLE_BUTTON(item), FALSE);
@@ -153,7 +153,7 @@ gboolean sidebar_item_show_dialog(Sideba
     GtkWidget* icon_pe;
     gint result;
 
-    g_return_if_fail(IS_SIDEBAR_ITEM(item));
+    g_return_val_if_fail(IS_SIDEBAR_ITEM(item), FALSE);
 
     dlg = gtk_dialog_new_with_buttons(_("Playlist Properties"),
             liteamp_get_app_window(),
