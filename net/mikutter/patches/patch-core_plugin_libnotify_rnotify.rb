$NetBSD: patch-core_plugin_libnotify_rnotify.rb,v 1.1 2013/08/14 13:06:13 obache Exp $

* fixes module name

--- core/plugin/libnotify/rnotify.rb.orig	2013-08-13 23:22:37.000000000 +0000
+++ core/plugin/libnotify/rnotify.rb
@@ -14,7 +14,7 @@ Plugin::create(:libnotify) do
     end
 
     if user
-      icon = Gtk::WebImageLoader.local_path(user[:profile_image_url])
+      icon = Gdk::WebImageLoader.local_path(user[:profile_image_url])
       title = "@#{user[:idname]} (#{user[:name]})"
     end
 
