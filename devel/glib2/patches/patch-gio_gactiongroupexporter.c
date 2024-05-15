$NetBSD: patch-gio_gactiongroupexporter.c,v 1.1 2024/05/15 13:43:00 wiz Exp $

gmenuexporter: Fix a NULL pointer dereference on an error handling path 
https://gitlab.gnome.org/GNOME/glib/-/merge_requests/4073

--- gio/gactiongroupexporter.c.orig	2024-05-08 15:29:04.000000000 +0000
+++ gio/gactiongroupexporter.c
@@ -531,10 +531,8 @@ org_gtk_Actions_method_call (GDBusConnec
 }
 
 static void
-g_action_group_exporter_free (gpointer user_data)
+g_action_group_exporter_free (GActionGroupExporter *exporter)
 {
-  GActionGroupExporter *exporter = user_data;
-
   g_signal_handlers_disconnect_by_func (exporter->action_group,
                                         g_action_group_exporter_action_added, exporter);
   g_signal_handlers_disconnect_by_func (exporter->action_group,
@@ -616,15 +614,6 @@ g_dbus_connection_export_action_group (G
     }
 
   exporter = g_slice_new (GActionGroupExporter);
-  id = g_dbus_connection_register_object (connection, object_path, org_gtk_Actions, &vtable,
-                                          exporter, g_action_group_exporter_free, error);
-
-  if (id == 0)
-    {
-      g_slice_free (GActionGroupExporter, exporter);
-      return 0;
-    }
-
   exporter->context = g_main_context_ref_thread_default ();
   exporter->pending_changes = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, NULL);
   exporter->pending_source = NULL;
@@ -632,14 +621,20 @@ g_dbus_connection_export_action_group (G
   exporter->connection = g_object_ref (connection);
   exporter->object_path = g_strdup (object_path);
 
-  g_signal_connect (action_group, "action-added",
-                    G_CALLBACK (g_action_group_exporter_action_added), exporter);
-  g_signal_connect (action_group, "action-removed",
-                    G_CALLBACK (g_action_group_exporter_action_removed), exporter);
-  g_signal_connect (action_group, "action-state-changed",
-                    G_CALLBACK (g_action_group_exporter_action_state_changed), exporter);
-  g_signal_connect (action_group, "action-enabled-changed",
-                    G_CALLBACK (g_action_group_exporter_action_enabled_changed), exporter);
+  id = g_dbus_connection_register_object (connection, object_path, org_gtk_Actions, &vtable,
+                                          exporter, (GDestroyNotify) g_action_group_exporter_free, error);
+
+  if (id != 0)
+    {
+      g_signal_connect (action_group, "action-added",
+                        G_CALLBACK (g_action_group_exporter_action_added), exporter);
+      g_signal_connect (action_group, "action-removed",
+                        G_CALLBACK (g_action_group_exporter_action_removed), exporter);
+      g_signal_connect (action_group, "action-state-changed",
+                        G_CALLBACK (g_action_group_exporter_action_state_changed), exporter);
+      g_signal_connect (action_group, "action-enabled-changed",
+                        G_CALLBACK (g_action_group_exporter_action_enabled_changed), exporter);
+    }
 
   return id;
 }
