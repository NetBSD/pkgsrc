$NetBSD: patch-manhattanstyle.cpp,v 1.1 2020/06/10 06:36:14 markd Exp $

qt5.15 fix

--- src/manhattanstyle.cpp.orig	2020-01-15 19:10:58.000000000 +0000
+++ src/manhattanstyle.cpp
@@ -44,6 +44,7 @@
 #include <QMainWindow>
 #include <QMenuBar>
 #include <QPainter>
+#include <QPainterPath>
 #include <QPixmap>
 #include <QPixmapCache>
 #include <QPushButton>
