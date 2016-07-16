$NetBSD: patch-src_filelist_ctrl.cpp,v 1.1 2016/07/16 03:32:32 markd Exp $

--- src/filelist_ctrl.cpp.orig	2012-06-28 06:39:35.000000000 +0000
+++ src/filelist_ctrl.cpp
@@ -1606,7 +1606,7 @@ FileListCtrl::GetColumnVisible(const int
   }
 }
 
-inline void
+inline bool
 FileListCtrl::SetColumnWidth(const int col, const int width)
 {
   m->ColumnWidth[col] = width;
@@ -1616,6 +1616,7 @@ FileListCtrl::SetColumnWidth(const int c
   {
     wxListCtrl::SetColumnWidth(index, width);
   }
+  return true;
 }
 
 int
