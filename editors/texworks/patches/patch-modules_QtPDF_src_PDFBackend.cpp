$NetBSD: patch-modules_QtPDF_src_PDFBackend.cpp,v 1.1 2020/06/14 11:40:11 markd Exp $

qt5.15 fix

--- modules/QtPDF/src/PDFBackend.cpp.orig	2019-03-16 17:06:14.000000000 +0000
+++ modules/QtPDF/src/PDFBackend.cpp
@@ -14,6 +14,7 @@
 
 #include <PDFBackend.h>
 #include <QPainter>
+#include <QPainterPath>
 #include <QApplication>
 
 namespace QtPDF {
