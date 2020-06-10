$NetBSD: patch-mostQtHeaders.h,v 1.1 2020/06/10 06:36:14 markd Exp $

qt5.15 fix

--- src/mostQtHeaders.h.orig	2020-01-15 19:10:58.000000000 +0000
+++ src/mostQtHeaders.h
@@ -83,6 +83,7 @@
 #include <QObject>
 #include <QPaintEvent>
 #include <QPainter>
+#include <QPainterPath>
 #include <QPixmap>
 #include <QPixmapCache>
 #include <QPointer>
