$NetBSD: patch-lib_engine_components_libnotify_libnotify-main.cpp,v 1.2 2013/10/15 14:46:07 joerg Exp $

* for linbotify-0.7 API change

--- lib/engine/components/libnotify/libnotify-main.cpp.orig	2009-09-22 14:27:35.000000000 +0000
+++ lib/engine/components/libnotify/libnotify-main.cpp
@@ -36,7 +36,13 @@
  */
 
 #include <map>
+#if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 #include <libnotify/notify.h>
 
@@ -67,7 +73,7 @@ private:
   void on_notification_added (gmref_ptr<Ekiga::Notification> notif);
   void on_notification_removed (gmref_ptr<Ekiga::Notification> notif);
 
-  typedef std::map<gmref_ptr<Ekiga::Notification>, std::pair<sigc::connection, std::tr1::shared_ptr<NotifyNotification> > > container_type;
+  typedef std::map<gmref_ptr<Ekiga::Notification>, std::pair<sigc::connection, shared_ptr<NotifyNotification> > > container_type;
   container_type live;
 };
 
@@ -158,13 +164,13 @@ LibNotify::on_notification_added (gmref_
 
   notif = notify_notification_new (notification->get_title ().c_str (),
 				   notification->get_body ().c_str (),
-				   urgency, NULL);
+				   urgency);
 
   g_signal_connect (notif, "closed",
 		    G_CALLBACK (on_notif_closed), notification.get ());
   sigc::connection conn = notification->removed.connect (sigc::bind (sigc::mem_fun (this, &LibNotify::on_notification_removed), notification));
 
-  live[notification] = std::pair<sigc::connection, std::tr1::shared_ptr<NotifyNotification> > (conn, std::tr1::shared_ptr<NotifyNotification> (notif, g_object_unref));
+  live[notification] = std::pair<sigc::connection, shared_ptr<NotifyNotification> > (conn, shared_ptr<NotifyNotification> (notif, g_object_unref));
 
   (void)notify_notification_show (notif, NULL);
 }
