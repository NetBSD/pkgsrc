$NetBSD: patch-ext_extconf.rb,v 1.2 2015/06/10 14:47:59 taca Exp $

* not using gems in pkgsrc.

--- ext/extconf.rb.orig	2012-11-24 17:54:50.000000000 +0000
+++ ext/extconf.rb
@@ -5,8 +5,6 @@ type=0, DEBUG
 type=1, RELEASE
 =end
 
-require 'rubygems'
-
 begin
   require 'mkmf-gnome2'
   require 'gtk2'
@@ -43,7 +41,7 @@ end
 if check_required_version("libnotify", 0, 7, 0) == true
   if have_library("notify", "notify_init") == true
     $CFLAGS << ' -DDEBUG' if type == 0
-    $CFLAGS << ' -Wall' << " -I#{Config::CONFIG["sitearchdir"]} " << PKGConfig.cflags("libnotify")
+    $CFLAGS << ' -Wall' << " -I#{RbConfig::CONFIG["sitearchdir"]} " << PKGConfig.cflags("libnotify")
     $LIBS << ' ' << PKGConfig.libs("libnotify")
     check_set_app_name_libnotify
     check_set_notification_name_libnotify
