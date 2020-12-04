$NetBSD: patch-src_backend_bookshelfmodel_btbookshelftreemodel.cpp,v 1.1 2020/12/04 12:17:58 nros Exp $

* remove deprecation warning
 taken from upstream https://github.com/bibletime/bibletime/commit/6eb2938ed8b0244fda481c5fbfd7c00588c3d848

--- src/backend/bookshelfmodel/btbookshelftreemodel.cpp.orig	2020-08-02 18:32:25.000000000 +0000
+++ src/backend/bookshelfmodel/btbookshelftreemodel.cpp
@@ -214,7 +214,7 @@ bool BtBookshelfTreeModel::setData(const
 
 Qt::ItemFlags BtBookshelfTreeModel::flags(const QModelIndex & index) const {
     if (!index.isValid())
-        return nullptr;
+        return Qt::ItemFlags();
 
     Qt::ItemFlags f(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
 
