$NetBSD: patch-src_ui_clipboard.cpp,v 1.1 2016/04/12 21:33:49 adam Exp $

Fix building with newer glibmm.

--- src/ui/clipboard.cpp.orig	2016-04-12 21:18:03.000000000 +0000
+++ src/ui/clipboard.cpp
@@ -1402,7 +1402,7 @@ void ClipboardManagerImpl::_inkscape_wai
 
         Glib::ustring target;
         if (atom_name) {
-            target = Glib::ScopedPtr<char>(atom_name).get(); //This frees the gchar*.
+            target = Glib::make_unique_ptr_gfree(atom_name).get(); //This frees the gchar*.
         }
 
         listTargets.push_back(target);
