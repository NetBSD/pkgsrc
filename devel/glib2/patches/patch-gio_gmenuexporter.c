$NetBSD: patch-gio_gmenuexporter.c,v 1.1 2024/05/15 13:43:00 wiz Exp $

gmenuexporter: Fix a NULL pointer dereference on an error handling path 
https://gitlab.gnome.org/GNOME/glib/-/merge_requests/4073

--- gio/gmenuexporter.c.orig	2024-05-08 15:29:04.000000000 +0000
+++ gio/gmenuexporter.c
@@ -707,11 +707,9 @@ g_menu_exporter_create_group (GMenuExpor
 }
 
 static void
-g_menu_exporter_free (gpointer user_data)
+g_menu_exporter_free (GMenuExporter *exporter)
 {
-  GMenuExporter *exporter = user_data;
-
-  g_menu_exporter_menu_free (exporter->root);
+  g_clear_pointer (&exporter->root, g_menu_exporter_menu_free);
   g_clear_pointer (&exporter->peer_remote, g_menu_exporter_remote_free);
   g_hash_table_unref (exporter->remotes);
   g_hash_table_unref (exporter->groups);
@@ -794,21 +792,16 @@ g_dbus_connection_export_menu_model (GDB
   guint id;
 
   exporter = g_slice_new0 (GMenuExporter);
-
-  id = g_dbus_connection_register_object (connection, object_path, org_gtk_Menus_get_interface (),
-                                          &vtable, exporter, g_menu_exporter_free, error);
-
-  if (id == 0)
-    {
-      g_slice_free (GMenuExporter, exporter);
-      return 0;
-    }
-
   exporter->connection = g_object_ref (connection);
   exporter->object_path = g_strdup (object_path);
   exporter->groups = g_hash_table_new (NULL, NULL);
   exporter->remotes = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_menu_exporter_remote_free);
-  exporter->root = g_menu_exporter_group_add_menu (g_menu_exporter_create_group (exporter), menu);
+
+  id = g_dbus_connection_register_object (connection, object_path, org_gtk_Menus_get_interface (),
+                                          &vtable, exporter, (GDestroyNotify) g_menu_exporter_free, error);
+
+  if (id != 0)
+    exporter->root = g_menu_exporter_group_add_menu (g_menu_exporter_create_group (exporter), menu);
 
   return id;
 }
