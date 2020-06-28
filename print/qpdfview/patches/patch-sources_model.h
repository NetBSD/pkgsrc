$NetBSD: patch-sources_model.h,v 1.1 2020/06/28 14:55:17 nia Exp $

Fix Qt 5.15 fallout.

--- sources/model.h.orig	2019-07-24 19:18:33.000000000 +0000
+++ sources/model.h
@@ -24,6 +24,7 @@ along with qpdfview.  If not, see <http:
 #define DOCUMENTMODEL_H
 
 #include <QList>
+#include <QPainterPath>
 #include <QtPlugin>
 #include <QWidget>
 #include <QVector>
