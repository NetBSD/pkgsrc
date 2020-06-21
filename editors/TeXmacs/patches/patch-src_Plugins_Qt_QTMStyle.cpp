$NetBSD: patch-src_Plugins_Qt_QTMStyle.cpp,v 1.1 2020/06/21 03:54:54 mef Exp $

Adapt to QT 5.15.0

--- src/Plugins/Qt/QTMStyle.cpp.orig	2020-05-28 08:56:46.524435324 +0000
+++ src/Plugins/Qt/QTMStyle.cpp
@@ -19,6 +19,7 @@
 #include <qdrawutil.h>
 #include <QPainter>
 #include <QMainWindow>
+#include <QPainterPath>
 
 int
 qt_zoom (int sz) {
