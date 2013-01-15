$NetBSD: patch-src_ratiowidget.cpp,v 1.1 2013/01/15 15:24:19 joerg Exp $

--- src/ratiowidget.cpp.orig	2013-01-14 22:46:45.000000000 +0000
+++ src/ratiowidget.cpp
@@ -26,8 +26,7 @@
 //Added by qt3to4:
 #include <QPaintEvent>
 
-RatioWidget::RatioWidget(QWidget * parent = 0,
-                         const ratio para_ratio = ratio()) :
+RatioWidget::RatioWidget(QWidget * parent, const ratio para_ratio) :
     FractionBaseWidget(parent), m_ratio(para_ratio)
 {
 #ifdef DEBUG
