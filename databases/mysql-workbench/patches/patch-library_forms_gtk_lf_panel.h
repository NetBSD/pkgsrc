$NetBSD: patch-library_forms_gtk_lf_panel.h,v 1.1.1.1 2011/05/16 12:40:50 adam Exp $

Sacrifice sel_color to fix compilation with newer Gtkmm.

--- library/forms/gtk/lf_panel.h.orig	2011-05-16 08:57:29.000000000 +0000
+++ library/forms/gtk/lf_panel.h
@@ -45,11 +45,11 @@ protected:
   PanelImpl(::mforms::Panel *self, ::mforms::PanelType type)
     : ContainerImpl(self), _frame(0), _evbox(0), _radio_group_set(false)
   {
-    static Gdk::Color sel_color;
+//    static Gdk::Color sel_color;
     static bool initialized = false;
     if (!initialized)
     {
-      sel_color = Gtk::RC::get_style(Gtk::TreeView())->get_bg(Gtk::STATE_SELECTED);
+//      sel_color = Gtk::RC::get_style(Gtk::TreeView())->get_bg(Gtk::STATE_SELECTED);
       initialized = true;
     }
 
@@ -62,7 +62,7 @@ protected:
       break;
     case StyledHeaderPanel:      // just a container with color filled background
       _evbox= Gtk::manage(new Gtk::EventBox());
-      _evbox->modify_bg(Gtk::STATE_NORMAL, sel_color);
+//      _evbox->modify_bg(Gtk::STATE_NORMAL, sel_color);
       break;
     case FilledPanel:      // just a container with color filled background
       _evbox= Gtk::manage(new Gtk::EventBox());
