$NetBSD: patch-libgui_src_workspace-model.cc,v 1.2 2016/08/06 13:03:35 prlw1 Exp $

Changes for compiling with Qt5 instead of Qt4

--- libgui/src/workspace-model.cc.orig	2015-05-23 14:21:53.000000000 +0000
+++ libgui/src/workspace-model.cc
@@ -132,7 +132,7 @@ workspace_model::data (const QModelIndex
         {
           QString class_chars = resource_manager::storage_class_chars ();
           int actual_class
-            = class_chars.indexOf (_scopes[idx.row ()].toAscii ());
+            = class_chars.indexOf (_scopes[idx.row ()].toLatin1 ());
           if (actual_class >= 0)
             return QVariant (_storage_class_colors.at (actual_class));
           else
@@ -172,7 +172,7 @@ workspace_model::data (const QModelIndex
                 QString class_chars = resource_manager::storage_class_chars ();
 
                 int actual_class
-                  = class_chars.indexOf (_scopes[idx.row ()].toAscii ());
+                  = class_chars.indexOf (_scopes[idx.row ()].toLatin1 ());
 
                 if (actual_class >= 0)
                   {
