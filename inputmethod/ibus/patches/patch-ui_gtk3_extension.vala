$NetBSD: patch-ui_gtk3_extension.vala,v 1.1 2020/10/17 05:25:46 mef Exp $

 Fix Error: 
extension.vala:54.37-54.56: error: Argument 7: Cannot convert from `void ExtensionGtk.bus_name_acquired_cb (GLib.DBusConnection, string, string, string, string, GLib.Variant)' to `void GLib.DBusSignalCallback (GLib.DBusConnection, string?, string, string, string, GLib.Variant)'
                                    bus_name_acquired_cb);
                                    ^^^^^^^^^^^^^^^^^^^^
   git clone https://github.com/ibus/ibus.git
   git show dd4cc5b028c35f9bb8f
 
   Info provided by @tristelo of Twitter, thanks

--- ui/gtk3/extension.vala.orig	2020-10-17 05:13:08.696559322 +0000
+++ ui/gtk3/extension.vala
@@ -67,7 +67,7 @@ class ExtensionGtk : Gtk.Application {
 
 
     private void bus_name_acquired_cb(DBusConnection connection,
-                                      string sender_name,
+                                      string? sender_name,
                                       string object_path,
                                       string interface_name,
                                       string signal_name,
@@ -78,7 +78,7 @@ class ExtensionGtk : Gtk.Application {
     }
 
     private void bus_name_lost_cb(DBusConnection connection,
-                                  string sender_name,
+                                  string? sender_name,
                                   string object_path,
                                   string interface_name,
                                   string signal_name,
