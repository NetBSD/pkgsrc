$NetBSD: patch-libgui_src_resource-manager.cc,v 1.1 2016/02/16 04:21:40 dbj Exp $

Changes for compiling with Qt5 instead of Qt4

--- libgui/src/resource-manager.cc.orig	2015-05-23 14:21:54.000000000 +0000
+++ libgui/src/resource-manager.cc
@@ -61,10 +61,8 @@ resource_manager::resource_manager (void
   : settings_directory (), settings_file (), settings (0),
     default_settings (0)
 {
-  QDesktopServices desktopServices;
-
   QString home_path
-    = desktopServices.storageLocation (QDesktopServices::HomeLocation);
+    = QStandardPaths::writableLocation (QStandardPaths::HomeLocation);
 
   settings_directory = home_path + "/.config/octave";
 
