$NetBSD: patch-ui_gtk3_application.vala,v 1.1 2020/10/17 05:25:46 mef Exp $

 Fix Build Error:

   git clone https://github.com/ibus/ibus.git
   git show dd4cc5b028c35f9bb8f

   Info provided by @tristelo of Twitter, thanks

--- ui/gtk3/application.vala.orig	2020-10-17 05:12:46.065207466 +0000
+++ ui/gtk3/application.vala
@@ -69,7 +69,7 @@ class Application {
     }
 
     private void bus_name_acquired_cb(DBusConnection connection,
-                                      string sender_name,
+                                      string? sender_name,
                                       string object_path,
                                       string interface_name,
                                       string signal_name,
@@ -80,7 +80,7 @@ class Application {
     }
 
     private void bus_name_lost_cb(DBusConnection connection,
-                                  string sender_name,
+                                  string? sender_name,
                                   string object_path,
                                   string interface_name,
                                   string signal_name,
