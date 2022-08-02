$NetBSD: patch-src_actions_actions-edit.cpp,v 1.2 2022/08/02 07:31:05 wiz Exp $

Fix collision with clone() from sched.h on NetBSD.
https://gitlab.com/inkscape/inkscape/-/merge_requests/4679

--- src/actions/actions-edit.cpp.orig	2022-07-14 13:10:04.000000000 +0000
+++ src/actions/actions-edit.cpp
@@ -23,6 +23,8 @@
 #include "ui/tools/text-tool.h"
 #include "ui/tools/node-tool.h"
 
+namespace ActionsEdit {
+
 void
 object_to_pattern(InkscapeApplication *app)
 {
@@ -302,6 +304,10 @@ std::vector<std::vector<Glib::ustring>> 
     // clang-format on
 };
 
+}
+
+using namespace ActionsEdit;
+
 void
 add_actions_edit(InkscapeApplication* app)
 {
@@ -322,7 +328,7 @@ add_actions_edit(InkscapeApplication* ap
     gapp->add_action( "paste-width-separately",          sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&paste_width_separately), app));
     gapp->add_action( "paste-height-separately",         sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&paste_height_separately), app));
     gapp->add_action( "duplicate",                       sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&duplicate), app));
-    gapp->add_action( "clone",                           sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&clone), app));
+    gapp->add_action( "clone",                           sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&ActionsEdit::clone), app));
     gapp->add_action( "clone-unlink",                    sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&clone_unlink), app));
     gapp->add_action( "clone-unlink-recursively",        sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&clone_unlink_recursively), app));
     gapp->add_action( "clone-link",                      sigc::bind<InkscapeApplication*>(sigc::ptr_fun(&clone_link), app));
