$NetBSD: patch-src_MainWindow.vala,v 1.1 2020/08/02 22:15:05 mef Exp $

MainWindow.vala:438.40-438.41: error: Assignment: Cannot convert from `GLib.List<Gtk.Window>' to `GLib.List<weak Gtk.Window>?'
    unowned GLib.List<weak Gtk.Window> ws = this.application.get_windows ();


--- src/MainWindow.vala.orig	2020-08-02 21:40:19.483990912 +0000
+++ src/MainWindow.vala
@@ -435,7 +435,7 @@ public class MainWindow : Gtk.Applicatio
     if (account == null)
       return Gdk.EVENT_PROPAGATE;
 
-    unowned GLib.List<weak Gtk.Window> ws = this.application.get_windows ();
+    unowned GLib.List<Gtk.Window> ws = this.application.get_windows ();
     debug("Windows: %u", ws.length ());
 
     string[] startup_accounts = Settings.get ().get_strv ("startup-accounts");
