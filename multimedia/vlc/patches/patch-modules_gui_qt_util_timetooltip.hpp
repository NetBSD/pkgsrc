$NetBSD: patch-modules_gui_qt_util_timetooltip.hpp,v 1.1 2020/06/07 02:02:45 markd Exp $

qt5.15 patch

--- modules/gui/qt/util/timetooltip.hpp.orig	2018-05-03 12:03:21.000000000 +0000
+++ modules/gui/qt/util/timetooltip.hpp
@@ -24,6 +24,7 @@
 
 #include "qt.hpp"
 
+#include <QPainterPath>
 #include <QWidget>
 
 class TimeTooltip : public QWidget
