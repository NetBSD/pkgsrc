$NetBSD: patch-kbruch_src_ratiowidget.cpp,v 1.1 2013/01/15 15:27:19 joerg Exp $

--- kbruch/src/ratiowidget.cpp.orig	2013-01-14 20:28:58.000000000 +0000
+++ kbruch/src/ratiowidget.cpp
@@ -21,8 +21,8 @@
 /* these includes are needed for Qt support */
 #include <qpainter.h>
 
-RatioWidget::RatioWidget(QWidget * parent = 0, const char * name = 0,
-													const ratio para_ratio = *new ratio()) :
+RatioWidget::RatioWidget(QWidget * parent, const char * name,
+													const ratio para_ratio) :
 			FractionBaseWidget(parent, name), m_ratio(para_ratio)
 {
 #ifdef DEBUG
