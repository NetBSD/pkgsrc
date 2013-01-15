$NetBSD: patch-kbruch_src_fractionbasewidget.cpp,v 1.1 2013/01/15 15:27:19 joerg Exp $

--- kbruch/src/fractionbasewidget.cpp.orig	2013-01-14 20:28:25.000000000 +0000
+++ kbruch/src/fractionbasewidget.cpp
@@ -26,7 +26,7 @@
 
 #include "settingsclass.h"
 
-FractionBaseWidget::FractionBaseWidget(QWidget * parent = 0, const char * name = 0) :
+FractionBaseWidget::FractionBaseWidget(QWidget * parent, const char * name) :
 			QWidget(parent, name)
 {
 #ifdef DEBUG
