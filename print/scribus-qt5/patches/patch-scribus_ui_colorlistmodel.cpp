$NetBSD: patch-scribus_ui_colorlistmodel.cpp,v 1.1 2020/06/14 07:35:58 ryoon Exp $

* Fix segfault.

--- scribus/ui/colorlistmodel.cpp.orig	2020-06-11 09:56:15.000000000 +0000
+++ scribus/ui/colorlistmodel.cpp
@@ -31,8 +31,6 @@ ColorPixmapValue::ColorPixmapValue( cons
 	m_name = colName;
 }
 
-ColorPixmapValue ColorListModel::m_NoneColor(ScColor(), nullptr, CommonStrings::None);
-
 ColorListModel::ColorListModel(QObject *parent)
 	          : QAbstractItemModel(parent)
 {
