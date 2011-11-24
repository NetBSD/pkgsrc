$NetBSD: patch-src_colorcorrection_vectorscopegenerator.h,v 1.1 2011/11/24 13:44:02 joerg Exp $

--- src/colorcorrection/vectorscopegenerator.h.orig	2011-11-24 01:33:48.000000000 +0000
+++ src/colorcorrection/vectorscopegenerator.h
@@ -12,6 +12,7 @@
 #define VECTORSCOPEGENERATOR_H
 
 #include <QObject>
+#include <QImage>
 
 class QImage;
 class QPoint;
