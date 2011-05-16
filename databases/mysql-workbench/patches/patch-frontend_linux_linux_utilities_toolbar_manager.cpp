$NetBSD: patch-frontend_linux_linux_utilities_toolbar_manager.cpp,v 1.1.1.1 2011/05/16 12:40:50 adam Exp $

Fix building with newer Gtkmm.

--- frontend/linux/linux_utilities/toolbar_manager.cpp.orig	2011-05-16 11:11:25.000000000 +0000
+++ frontend/linux/linux_utilities/toolbar_manager.cpp
@@ -31,7 +31,7 @@ static Gtk::ComboBox *create_color_combo
   }
 
   Glib::RefPtr<Gtk::ListStore> model= Gtk::ListStore::create(*color_combo_columns);
-  Gtk::ComboBox *combo= new Gtk::ComboBox(model);
+  Gtk::ComboBox *combo= new Gtk::ComboBox(model, false);
 
   combo->pack_start(color_combo_columns->image);
 
