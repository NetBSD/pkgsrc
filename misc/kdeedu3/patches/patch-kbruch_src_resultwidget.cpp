$NetBSD: patch-kbruch_src_resultwidget.cpp,v 1.1 2013/01/15 15:27:19 joerg Exp $

--- kbruch/src/resultwidget.cpp.orig	2013-01-14 20:28:37.000000000 +0000
+++ kbruch/src/resultwidget.cpp
@@ -23,8 +23,8 @@
 
 #include "settingsclass.h"
 
-ResultWidget::ResultWidget(QWidget * parent = 0, const char * name = 0,
-													const ratio para_result = *new ratio()) :
+ResultWidget::ResultWidget(QWidget * parent, const char * name,
+													const ratio para_result) :
 			FractionBaseWidget(parent, name), m_result(para_result)
 {
 #ifdef DEBUG
