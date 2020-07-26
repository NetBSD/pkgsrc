$NetBSD: patch-src_libs_ui_searchitemdelegate.cpp,v 1.1 2020/07/26 00:51:00 scole Exp $

add QPainterPath to includes

--- src/libs/ui/searchitemdelegate.cpp.orig	2018-09-28 05:26:37.000000000 +0000
+++ src/libs/ui/searchitemdelegate.cpp
@@ -27,6 +27,7 @@
 #include <QFontMetrics>
 #include <QHelpEvent>
 #include <QPainter>
+#include <QPainterPath>
 #include <QToolTip>
 
 using namespace Zeal::WidgetUi;
