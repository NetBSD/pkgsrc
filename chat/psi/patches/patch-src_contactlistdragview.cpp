$NetBSD: patch-src_contactlistdragview.cpp,v 1.1 2020/06/18 13:55:15 nia Exp $

Fix Qt 5.15 build issues

--- src/contactlistdragview.cpp.orig	2018-11-02 00:15:39.000000000 +0000
+++ src/contactlistdragview.cpp
@@ -43,6 +43,7 @@
 #include <QMimeData>
 #include <QMouseEvent>
 #include <QPainter>
+#include <QPainterPath>
 #include <QScrollBar>
 #include <QMessageBox>
 
