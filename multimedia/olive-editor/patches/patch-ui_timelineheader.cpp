$NetBSD: patch-ui_timelineheader.cpp,v 1.1 2020/06/18 14:52:12 nia Exp $

Fix Qt 5.15 build issues

--- ui/timelineheader.cpp.orig	2019-07-09 15:16:17.000000000 +0000
+++ ui/timelineheader.cpp
@@ -21,6 +21,7 @@
 #include "timelineheader.h"
 
 #include <QPainter>
+#include <QPainterPath>
 #include <QMouseEvent>
 #include <QScrollBar>
 #include <QtMath>
