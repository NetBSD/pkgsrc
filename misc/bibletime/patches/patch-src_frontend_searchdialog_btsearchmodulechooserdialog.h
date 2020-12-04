$NetBSD: patch-src_frontend_searchdialog_btsearchmodulechooserdialog.h,v 1.1 2020/12/04 12:17:59 nros Exp $

* remove deprecation warning
 taken from upstream https://github.com/bibletime/bibletime/commit/6eb2938ed8b0244fda481c5fbfd7c00588c3d848

--- src/frontend/searchdialog/btsearchmodulechooserdialog.h.orig	2020-11-28 18:53:24.250680326 +0000
+++ src/frontend/searchdialog/btsearchmodulechooserdialog.h
@@ -26,7 +26,7 @@ class BtSearchModuleChooserDialog: publi
     Q_OBJECT
     public:
         BtSearchModuleChooserDialog(QWidget *parent = nullptr,
-                                    Qt::WindowFlags flags = nullptr);
+                                    Qt::WindowFlags flags = Qt::WindowFlags());
 
         inline void setCheckedModules(BtConstModuleSet const & modules)
         { bookshelfWidget()->treeModel()->setCheckedModules(modules); }
