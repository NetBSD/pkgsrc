$NetBSD: patch-src_SkewT.h,v 1.1 2024/06/27 12:31:32 bouyer Exp $

Fix undeclared class QPainterPath 

--- src/SkewT.h.orig	2020-08-21 13:09:55.133572321 +0200
+++ src/SkewT.h	2020-08-21 13:10:05.207772962 +0200
@@ -16,6 +16,7 @@
 #include <QMainWindow>
 #include <QFrame>
 #include <QPainter>
+#include <QPainterPath>
 #include <QLayout>
 #include <QKeyEvent>
 #include <QPrintDialog>
