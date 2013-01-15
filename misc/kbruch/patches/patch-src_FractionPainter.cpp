$NetBSD: patch-src_FractionPainter.cpp,v 1.1 2013/01/15 15:24:19 joerg Exp $

--- src/FractionPainter.cpp.orig	2013-01-14 22:49:24.000000000 +0000
+++ src/FractionPainter.cpp
@@ -28,7 +28,7 @@
 //Added by qt3to4:
 #include <QPaintEvent>
 
-FractionPainter::FractionPainter(QWidget * parent = 0) :
+FractionPainter::FractionPainter(QWidget * parent) :
     FractionBaseWidget(parent)
 {
 #ifdef DEBUG
