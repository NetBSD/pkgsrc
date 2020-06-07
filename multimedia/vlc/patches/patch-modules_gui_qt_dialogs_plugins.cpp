$NetBSD: patch-modules_gui_qt_dialogs_plugins.cpp,v 1.1 2020/06/07 02:02:45 markd Exp $

qt5.15 patch

--- modules/gui/qt/dialogs/plugins.cpp.orig	2017-11-24 15:29:17.000000000 +0000
+++ modules/gui/qt/dialogs/plugins.cpp
@@ -53,6 +53,7 @@
 #include <QListView>
 #include <QListWidget>
 #include <QPainter>
+#include <QPainterPath>
 #include <QStyleOptionViewItem>
 #include <QKeyEvent>
 #include <QPushButton>
