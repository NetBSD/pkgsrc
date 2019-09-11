$NetBSD: patch-src_ui__menu.cc,v 1.1 2019/09/11 16:26:17 micha Exp $

Fix internal name for Online Documentation menu entry.

--- src/ui_menu.cc.orig	2018-08-03 04:23:43.000000000 +0000
+++ src/ui_menu.cc
@@ -412,7 +412,8 @@ static void tools_do_view_logs(Fl_Widget
 
 static void help_do_online_docs(Fl_Widget *w, void * data)
 {
-	ExecuteCommand("Documentation");
+	//ExecuteCommand("Documentation");
+	ExecuteCommand("OnlineDocs");
 }
 
 static void help_do_about(Fl_Widget *w, void * data)
