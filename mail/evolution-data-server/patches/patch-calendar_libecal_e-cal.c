$NetBSD: patch-calendar_libecal_e-cal.c,v 1.1 2016/01/31 07:01:55 richard Exp $

The e-calendar-factory process did not terminate automatically
when the user logged out of the graphical desktop environment, and
e-calendar-factory thus redundantly consumed system resources.
(https://bugzilla.redhat.com/show_bug.cgi?id=1141760 and upstream
 https://bugzilla.gnome.org/show_bug.cgi?id=646117)

--- calendar/libecal/e-cal.c.orig	2011-04-21 19:36:35.000000000 +0000
+++ calendar/libecal/e-cal.c
@@ -709,7 +709,6 @@ e_cal_activate (GError **error)
 	}
 
 	connection = g_dbus_proxy_get_connection (G_DBUS_PROXY (cal_factory_proxy));
-	g_dbus_connection_set_exit_on_close (connection, FALSE);
 	cal_connection_closed_id = g_dbus_connection_signal_subscribe (connection,
 		NULL,						/* sender */
 		"org.freedesktop.DBus",				/* interface */
