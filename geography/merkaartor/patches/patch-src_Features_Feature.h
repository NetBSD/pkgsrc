$NetBSD: patch-src_Features_Feature.h,v 1.2 2020/09/02 00:24:26 gdt Exp $

--- src/Features/Feature.h.orig	2011-02-10 12:00:35.000000000 +0000
+++ src/Features/Feature.h
@@ -10,6 +10,7 @@ class Feature;

 #include <QtCore/QString>
 #include <QList>
+#include <QPainterPath>
 
 #define CAST_FEATURE(x) (dynamic_cast<Feature*>(x))
 #define CAST_NODE(x) (dynamic_cast<Node*>(x))

