$NetBSD: patch-src_qtterminal_QtGnuplotItems.h,v 1.1 2024/06/05 13:56:14 adam Exp $

Use proper includes.

--- src/qtterminal/QtGnuplotItems.h.orig	2024-05-16 12:05:32.052464582 +0000
+++ src/qtterminal/QtGnuplotItems.h
@@ -44,9 +44,9 @@
 #ifndef QTGNUPLOTITEMS_H
 #define QTGNUPLOTITEMS_H
 
-#include <QGraphicsItem>
-#include <QFont>
-#include <QPen>
+#include <QtWidgets/QGraphicsItem>
+#include <QtGui/QFont>
+#include <QtGui/QPen>
 
 class QtGnuplotPoint : public QGraphicsItem
 {
