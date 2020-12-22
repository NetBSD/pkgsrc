$NetBSD: patch-widgets_ColorThemeListView.cpp,v 1.1 2020/12/22 09:58:52 nia Exp $

Fix compatibility with Qt 5.15.0.

--- widgets/ColorThemeListView.cpp.orig	2019-07-08 21:53:27.000000000 +0000
+++ widgets/ColorThemeListView.cpp
@@ -3,6 +3,7 @@
 #include <QJsonArray>
 #include <QMap>
 #include <QPainter>
+#include <QPainterPath>
 #include <QFontMetrics>
 #include <QScreen>
 #include <QJsonArray>
