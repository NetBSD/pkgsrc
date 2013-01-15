$NetBSD: patch-kbruch_src_taskwidget.cpp,v 1.1 2013/01/15 15:27:19 joerg Exp $

--- kbruch/src/taskwidget.cpp.orig	2013-01-14 20:27:09.000000000 +0000
+++ kbruch/src/taskwidget.cpp
@@ -24,8 +24,8 @@
 /* these includes are needed for Qt support */
 #include <qpainter.h>
 
-TaskWidget::TaskWidget(QWidget * parent = 0, const char * name = 0,
-													const task para_task = *new task()) :
+TaskWidget::TaskWidget(QWidget * parent, const char * name,
+													const task para_task) :
 			FractionBaseWidget(parent, name), m_task(para_task)
 {
 #ifdef DEBUG
