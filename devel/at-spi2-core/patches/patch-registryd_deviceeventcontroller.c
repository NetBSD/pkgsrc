$NetBSD: patch-registryd_deviceeventcontroller.c,v 1.1 2012/06/29 12:34:28 joerg Exp $

--- registryd/deviceeventcontroller.c.orig	2012-06-28 11:29:47.000000000 +0000
+++ registryd/deviceeventcontroller.c
@@ -1225,11 +1225,11 @@ send_and_allow_reentry (DBusConnection *
                                                 "org.freedesktop.DBus.Peer",
                                                 "Ping");
         if (!message)
-          return;
+          return NULL;
         dbus_connection_send_with_reply (bus, message, &pending, -1);
         dbus_message_unref (message);
         if (!pending)
-          return;
+          return NULL;
         bus_name_dup = g_strdup (dest);
         dbus_pending_call_set_notify (pending, reset_hung_process_from_ping,
                                       bus_name_dup, NULL);
