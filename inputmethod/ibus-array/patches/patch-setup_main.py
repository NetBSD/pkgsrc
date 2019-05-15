$NetBSD: patch-setup_main.py,v 1.1 2019/05/15 14:23:15 leot Exp $

Consistently use spaces instead of tabs to avoid Python 3 TabError-s.

--- setup/main.py.orig	2014-11-01 10:35:57.000000000 +0000
+++ setup/main.py
@@ -38,8 +38,8 @@ class Setup:
         self.__create_ui()
 
     def __create_ui(self):
-	gettext.bindtextdomain("ibus-array")
-	gettext.textdomain("ibus-array")
+        gettext.bindtextdomain("ibus-array")
+        gettext.textdomain("ibus-array")
         self.__window = Gtk.Dialog(_('ibus-array setup'), None, 
                                     Gtk.DialogFlags.MODAL, 
                                     (Gtk.STOCK_CANCEL, Gtk.ResponseType.CANCEL, 
@@ -97,9 +97,9 @@ class Setup:
                     self.__special_notify_button.set_active(False)
 
     def __read(self, name, v):
-	value = self.__config.get_value("engine/Array", name)
-	if value is None:
-		return v
+        value = self.__config.get_value("engine/Array", name)
+        if value is None:
+                return v
         return value
 
     def __write(self, name, v):
