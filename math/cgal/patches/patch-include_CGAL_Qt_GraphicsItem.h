$NetBSD: patch-include_CGAL_Qt_GraphicsItem.h,v 1.1 2016/01/17 15:17:10 joerg Exp $

qt4's moc can't deal with BOOST_JOIN in newer versions of Boost, so hide
the problematic includes.

--- include/CGAL/Qt/GraphicsItem.h.orig	2016-01-16 15:12:02.000000000 +0000
+++ include/CGAL/Qt/GraphicsItem.h
@@ -24,8 +24,9 @@
 #include <CGAL/auto_link/Qt4.h>
 #include <QObject>
 #include <QGraphicsItem>
+#ifndef Q_MOC_RUN
 #include <CGAL/Object.h>
-
+#endif
 
 
 namespace CGAL {
