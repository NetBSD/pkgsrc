$NetBSD: patch-src_actions_actions-edit.cpp,v 1.1 2022/07/25 19:42:33 wiz Exp $

Avoid confusion with clone(2) on NetBSD.
https://gitlab.com/inkscape/inbox/-/issues/7378

--- src/actions/actions-edit.cpp.orig	2022-07-14 13:10:04.000000000 +0000
+++ src/actions/actions-edit.cpp
@@ -150,7 +150,7 @@ duplicate(InkscapeApplication *app)
 }
 
 void
-clone(InkscapeApplication *app)
+inkscape_clone(InkscapeApplication *app)
 {
     auto selection = app->get_active_selection();
 
@@ -322,7 +322,7 @@ add_actions_edit(InkscapeApplication* ap
     gapp->add_action( "paste-width-separately",          sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&paste_width_separately), app));
     gapp->add_action( "paste-height-separately",         sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&paste_height_separately), app));
     gapp->add_action( "duplicate",                       sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&duplicate), app));
-    gapp->add_action( "clone",                           sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&clone), app));
+    gapp->add_action( "clone",                           sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&inkscape_clone), app));
     gapp->add_action( "clone-unlink",                    sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&clone_unlink), app));
     gapp->add_action( "clone-unlink-recursively",        sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&clone_unlink_recursively), app));
     gapp->add_action( "clone-link",                      sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&clone_link), app));
