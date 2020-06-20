$NetBSD: patch-SkewT.h,v 1.1 2020/06/20 21:34:26 mef Exp $

Adapt to QT 5.15.0

--- SkewT.h.orig	2020-06-20 21:17:55.224264430 +0000
+++ SkewT.h
@@ -31,6 +31,7 @@
 #include <QCheckBox>
 #include <QThread>
 #include <QMessageBox>
+#include <QPainterPath>
 
 class SkewT;
 
