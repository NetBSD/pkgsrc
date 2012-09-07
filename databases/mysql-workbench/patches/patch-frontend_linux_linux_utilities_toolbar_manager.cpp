$NetBSD: patch-frontend_linux_linux_utilities_toolbar_manager.cpp,v 1.2 2012/09/07 19:16:20 adam Exp $

Fix building with newer Gtkmm.

--- frontend/linux/linux_utilities/toolbar_manager.cpp.orig	2012-08-09 20:57:01.000000000 +0000
+++ frontend/linux/linux_utilities/toolbar_manager.cpp
@@ -30,7 +30,7 @@ static Gtk::ComboBox *create_color_combo
   }
 
   Glib::RefPtr<Gtk::ListStore> model= Gtk::ListStore::create(*color_combo_columns);
-  Gtk::ComboBox *combo= new Gtk::ComboBox(Glib::RefPtr<Gtk::TreeModel>(model));
+  Gtk::ComboBox *combo= new Gtk::ComboBox(Glib::RefPtr<Gtk::TreeModel>(model), false);
 
   combo->pack_start(color_combo_columns->image);
 
