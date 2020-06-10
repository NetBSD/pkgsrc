$NetBSD: patch-core_libs_dimg_filters_levels_histogrampainter.cpp,v 1.1 2020/06/10 11:08:05 markd Exp $

qt5.15 fix

--- core/libs/dimg/filters/levels/histogrampainter.cpp.orig	2019-11-03 09:03:59.000000000 +0000
+++ core/libs/dimg/filters/levels/histogrampainter.cpp
@@ -30,6 +30,7 @@
 // Qt includes
 
 #include <QPainter>
+#include <QPainterPath>
 
 // KDE includes
 
