$NetBSD: patch-IacPlot.h,v 1.1 2020/06/20 21:34:26 mef Exp $

Adapt to Qt 5.15.0

--- IacPlot.h.orig	2016-11-09 16:27:38.000000000 +0000
+++ IacPlot.h
@@ -31,6 +31,7 @@ Lecture mise en mémoire d'un fichier IA
 #include <QApplication>
 #include <QPainter>
 #include <QString>
+#include <QPainterPath>
 
 #include "DataMeteoAbstract.h"
 #include "zuFile.h"
