$NetBSD: patch-src_filelist_ctrl.hpp,v 1.1 2016/07/16 03:32:32 markd Exp $

--- src/filelist_ctrl.hpp.orig	2012-06-28 06:39:35.000000000 +0000
+++ src/filelist_ctrl.hpp
@@ -118,7 +118,7 @@ public:
    * @param col column number
    * @param width
    */
-  void
+  bool
   SetColumnWidth(const int col, const int width);
 
   /**
