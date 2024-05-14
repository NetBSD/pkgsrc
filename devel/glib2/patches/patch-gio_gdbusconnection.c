$NetBSD: patch-gio_gdbusconnection.c,v 1.1 2024/05/14 10:39:39 ryoon Exp $

* Revert https://github.com/GNOME/glib/commit/747e3af9987b37847d7d5acbf882d1ee4a6bd91b
  to fix startup of misc/libreoffice.

--- gio/gdbusconnection.c.orig	2024-05-14 10:29:05.451666538 +0000
+++ gio/gdbusconnection.c
@@ -5805,8 +5805,10 @@ g_dbus_connection_register_object (GDBus
  out:
   CONNECTION_UNLOCK (connection);
 
+#if 0
   if (ret == 0 && user_data_free_func != NULL)
     user_data_free_func (user_data);
+#endif
 
   return ret;
 }
@@ -7464,8 +7466,10 @@ g_dbus_connection_register_subtree (GDBu
  out:
   CONNECTION_UNLOCK (connection);
 
+#if 0
   if (ret == 0 && user_data_free_func != NULL)
     user_data_free_func (user_data);
+#endif
 
   return ret;
 }
