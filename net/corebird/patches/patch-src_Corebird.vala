$NetBSD: patch-src_Corebird.vala,v 1.1 2020/08/02 22:15:05 mef Exp $

Corebird.vala:414.40-414.46: error: Assignment: Cannot convert from `GLib.List<Gtk.Window>' to `GLib.List<weak Gtk.Window>?'
    unowned GLib.List<weak Gtk.Window> windows = this.get_windows ();
                                       ^^^^^^^
Corebird.vala:431.40-431.46: error: Assignment: Cannot convert from `GLib.List<Gtk.Window>' to `GLib.List<weak Gtk.Window>?'
    unowned GLib.List<weak Gtk.Window> windows = this.get_windows ();
                                       ^^^^^^^
Corebird.vala:399.40-399.46: error: Assignment: Cannot convert from `GLib.List<Gtk.Window>' to `GLib.List<weak Gtk.Window>?'
    unowned GLib.List<weak Gtk.Window> windows = this.get_windows ();

--- src/Corebird.vala.orig	2020-08-02 21:40:54.883977490 +0000
+++ src/Corebird.vala
@@ -396,7 +396,7 @@ public class Corebird : Gtk.Application 
    */
   public bool is_window_open_for_screen_name (string screen_name,
                                               out MainWindow? window = null) {
-    unowned GLib.List<weak Gtk.Window> windows = this.get_windows ();
+    unowned GLib.List<Gtk.Window> windows = this.get_windows ();
     foreach (Gtk.Window win in windows) {
       if (win is MainWindow) {
         if (((MainWindow)win).account.screen_name == screen_name) {
@@ -411,7 +411,7 @@ public class Corebird : Gtk.Application 
 
   public bool is_window_open_for_user_id (int64 user_id,
                                           out MainWindow? window = null) {
-    unowned GLib.List<weak Gtk.Window> windows = this.get_windows ();
+    unowned GLib.List<Gtk.Window> windows = this.get_windows ();
     foreach (Gtk.Window win in windows) {
       if (win is MainWindow) {
         if (((MainWindow)win).account.id == user_id) {
@@ -428,7 +428,7 @@ public class Corebird : Gtk.Application 
    * Quits the application, saving all open windows and their geometries.
    */
   private void quit_application () {
-    unowned GLib.List<weak Gtk.Window> windows = this.get_windows ();
+    unowned GLib.List<Gtk.Window> windows = this.get_windows ();
     string[] startup_accounts = Settings.get ().get_strv ("startup-accounts");
     if (startup_accounts.length == 1 && startup_accounts[0] == "")
       startup_accounts.resize (0);
