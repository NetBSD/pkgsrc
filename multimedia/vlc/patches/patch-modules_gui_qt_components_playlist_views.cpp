$NetBSD: patch-modules_gui_qt_components_playlist_views.cpp,v 1.1 2020/06/07 02:02:45 markd Exp $

qt5.15 patch

--- modules/gui/qt/components/playlist/views.cpp.orig	2017-11-24 15:29:17.000000000 +0000
+++ modules/gui/qt/components/playlist/views.cpp
@@ -27,6 +27,7 @@
 #include "input_manager.hpp"                      /* THEMIM */
 
 #include <QPainter>
+#include <QPainterPath>
 #include <QRect>
 #include <QStyleOptionViewItem>
 #include <QFontMetrics>
