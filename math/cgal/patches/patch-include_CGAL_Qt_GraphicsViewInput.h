$NetBSD: patch-include_CGAL_Qt_GraphicsViewInput.h,v 1.1 2016/01/17 15:17:10 joerg Exp $

qt4's moc can't deal with BOOST_JOIN in newer versions of Boost, so hide
the problematic includes.

--- include/CGAL/Qt/GraphicsViewInput.h.orig	2016-01-16 15:09:29.000000000 +0000
+++ include/CGAL/Qt/GraphicsViewInput.h
@@ -22,7 +22,9 @@
 #define CGAL_QT_GRAPHICS_VIEW_INPUT_H
 
 #include <CGAL/auto_link/Qt4.h>
+#ifndef Q_MOC_RUN
 #include <CGAL/Object.h>
+#endif
 #include <QObject>
 
 namespace CGAL {
