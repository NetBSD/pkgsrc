$NetBSD: patch-widgets_ColorPicker.cpp,v 1.1 2020/12/22 09:58:52 nia Exp $

Fix compatibility with Qt 5.15.0.

--- widgets/ColorPicker.cpp.orig	2019-07-08 21:53:27.000000000 +0000
+++ widgets/ColorPicker.cpp
@@ -3,6 +3,7 @@
 
 #include <QPaintEvent>
 #include <QPainter>
+#include <QPainterPath>
 #include <QMouseEvent>
 #include <QDesktopWidget>
 #include <QPixmap>
