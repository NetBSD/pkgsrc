$NetBSD: patch-src_modules_qt_producer__qtext.cpp,v 1.1 2020/06/07 04:35:25 markd Exp $

build with qt5.15

--- src/modules/qt/producer_qtext.cpp.orig	2020-02-16 22:31:58.000000000 +0000
+++ src/modules/qt/producer_qtext.cpp
@@ -26,6 +26,7 @@
 #include <QImage>
 #include <QColor>
 #include <QPainter>
+#include <QPainterPath>
 #include <QFont>
 #include <QString>
 #include <QTextCodec>
