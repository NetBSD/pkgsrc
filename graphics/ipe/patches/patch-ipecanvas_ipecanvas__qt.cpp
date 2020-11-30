$NetBSD: patch-ipecanvas_ipecanvas__qt.cpp,v 1.1 2020/11/30 13:34:41 nia Exp $

include <QPainterPath> to fix build with current version of Qt.

--- ipecanvas/ipecanvas_qt.cpp.orig	2016-12-09 14:09:05.000000000 +0000
+++ ipecanvas/ipecanvas_qt.cpp
@@ -35,6 +35,7 @@
 #include <cairo.h>
 
 #include <QPainter>
+#include <QPainterPath>
 #include <QPaintEvent>
 
 using namespace ipe;
