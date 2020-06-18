$NetBSD: patch-ui_graphview.cpp,v 1.1 2020/06/18 14:52:12 nia Exp $

Fix Qt 5.15 build issues

--- ui/graphview.cpp.orig	2019-07-09 15:16:17.000000000 +0000
+++ ui/graphview.cpp
@@ -21,6 +21,7 @@
 #include "graphview.h"
 
 #include <QPainter>
+#include <QPainterPath>
 #include <QMouseEvent>
 #include <QtMath>
 #include <cfloat>
