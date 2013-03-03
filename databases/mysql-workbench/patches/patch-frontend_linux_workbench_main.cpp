$NetBSD: patch-frontend_linux_workbench_main.cpp,v 1.1 2013/03/03 04:54:26 joerg Exp $

--- frontend/linux/workbench/main.cpp.orig	2013-03-02 18:50:58.000000000 +0000
+++ frontend/linux/workbench/main.cpp
@@ -57,7 +57,7 @@ static Gtk::Window *show_splash()
       Gtk::Window *window= new Gtk::Window(Gtk::WINDOW_TOPLEVEL);
       window->set_decorated(false);
       window->set_default_size(560, 322);
-      window->modify_bg_pixmap(Gtk::STATE_NORMAL, std::string(datadir).append("/images/"SPLASH_IMAGE));
+      window->modify_bg_pixmap(Gtk::STATE_NORMAL, std::string(datadir).append("/images/" SPLASH_IMAGE));
       window->set_position(Gtk::WIN_POS_CENTER);
       
       Gtk::Fixed *fixed= Gtk::manage(new Gtk::Fixed());
