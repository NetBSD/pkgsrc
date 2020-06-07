$NetBSD: patch-src_modules_qt_filter__qtext.cpp,v 1.1 2020/06/07 04:35:25 markd Exp $

build with qt5.15

--- src/modules/qt/filter_qtext.cpp.orig	2020-02-16 22:31:58.000000000 +0000
+++ src/modules/qt/filter_qtext.cpp
@@ -21,6 +21,7 @@
 #include <framework/mlt.h>
 #include <framework/mlt_log.h>
 #include <QPainter>
+#include <QPainterPath>
 #include <QString>
 
 static QRectF get_text_path( QPainterPath* qpath, mlt_properties filter_properties, const char* text, double scale )
