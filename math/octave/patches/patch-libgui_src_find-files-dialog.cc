$NetBSD: patch-libgui_src_find-files-dialog.cc,v 1.1 2016/02/16 04:21:40 dbj Exp $

--- libgui/src/find-files-dialog.cc.orig	2015-05-23 14:21:53.000000000 +0000
+++ libgui/src/find-files-dialog.cc
@@ -125,7 +125,7 @@ find_files_dialog::find_files_dialog (QW
   _file_list->horizontalHeader ()->restoreState (
     settings->value ("findfiles/column_state").toByteArray ());
   _file_list->horizontalHeader ()->setSortIndicatorShown (true);
-  _file_list->horizontalHeader ()->setClickable (true);
+  _file_list->horizontalHeader ()->setSectionsClickable (true);
   _file_list->horizontalHeader ()->setStretchLastSection (true);
   _file_list->sortByColumn (
                 settings->value ("findfiles/sort_files_by_column",0).toInt (),
