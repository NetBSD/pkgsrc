$NetBSD: patch-libgui_src_workspace-view.cc,v 1.1 2016/08/06 13:03:35 prlw1 Exp $

Changes for compiling with Qt5 instead of Qt4

--- libgui/src/workspace-view.cc.orig	2016-04-20 18:23:57.000000000 +0000
+++ libgui/src/workspace-view.cc
@@ -98,8 +98,8 @@ workspace_view::workspace_view (QWidget 
   view->horizontalHeader ()->restoreState (
     settings->value ("workspaceview/column_state").toByteArray ());
   // Set header properties for sorting
-  view->horizontalHeader ()->setClickable (true);
-  view->horizontalHeader ()->setMovable (true);
+  view->horizontalHeader ()->setSectionsClickable (true);
+  view->horizontalHeader ()->setSectionsMovable (true);
   view->horizontalHeader ()->setSortIndicator (
     settings->value ("workspaceview/sort_by_column",0).toInt (),
     static_cast<Qt::SortOrder>
