$NetBSD: patch-src_taskwidget.cpp,v 1.1 2013/01/15 15:24:19 joerg Exp $

--- src/taskwidget.cpp.orig	2013-01-14 22:45:53.000000000 +0000
+++ src/taskwidget.cpp
@@ -30,8 +30,7 @@
 //Added by qt3to4:
 #include <QPaintEvent>
 
-TaskWidget::TaskWidget(QWidget * parent = 0,
-                       const task para_task = task()) :
+TaskWidget::TaskWidget(QWidget * parent, const task para_task) :
     FractionBaseWidget(parent), m_task(para_task)
 {
 #ifdef DEBUG
