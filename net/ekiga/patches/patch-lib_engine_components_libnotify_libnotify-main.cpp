$NetBSD: patch-lib_engine_components_libnotify_libnotify-main.cpp,v 1.1 2013/08/16 05:53:02 obache Exp $

* for linbotify-0.7 API change

--- lib/engine/components/libnotify/libnotify-main.cpp.orig	2009-09-22 14:27:35.000000000 +0000
+++ lib/engine/components/libnotify/libnotify-main.cpp
@@ -158,7 +158,7 @@ LibNotify::on_notification_added (gmref_
 
   notif = notify_notification_new (notification->get_title ().c_str (),
 				   notification->get_body ().c_str (),
-				   urgency, NULL);
+				   urgency);
 
   g_signal_connect (notif, "closed",
 		    G_CALLBACK (on_notif_closed), notification.get ());
