$NetBSD: patch-src_qtterminal_QtGnuplotScene.h,v 1.1 2024/06/05 13:56:14 adam Exp $

Use proper includes.

--- src/qtterminal/QtGnuplotScene.h.orig	2024-05-16 12:07:29.007371294 +0000
+++ src/qtterminal/QtGnuplotScene.h
@@ -47,8 +47,8 @@
 #include "QtGnuplotEvent.h"
 #include "QtGnuplotItems.h"
 
-#include <QGraphicsScene>
-#include <QGraphicsItemGroup>
+#include <QtWidgets/QGraphicsScene>
+#include <QtWidgets/QGraphicsItemGroup>
 
 #if (QT_VERSION < QT_VERSION_CHECK(4, 7, 0))
 # include <QTime>
