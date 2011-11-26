$NetBSD: patch-mcs_gtk-bind.h,v 1.1 2011/11/26 17:08:51 joerg Exp $

--- mcs/gtk-bind.h.orig	2011-11-26 14:44:14.000000000 +0000
+++ mcs/gtk-bind.h
@@ -92,7 +92,7 @@ namespace Mcs
 
     public:
 
-      Bind (Mcs::Mcs * mcs);
+      Bind (Mcs * mcs);
       ~Bind ();
 
       void
@@ -147,7 +147,7 @@ namespace Mcs
 
     private:
 
-      Mcs::Mcs *mcs;
+      Mcs *mcs;
 
       void
       action_toggled_cb       (Glib::RefPtr<Gtk::ToggleAction> const& toggle_action,
