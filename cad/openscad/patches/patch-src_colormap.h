$NetBSD: patch-src_colormap.h,v 1.2 2019/06/22 12:57:50 mef Exp $

the Qt4 moc has some difficulty parsing in the boost headers. Apply
the workaround from https://bugreports.qt.io/browse/QTBUG-22829

--- src/colormap.h.orig	2018-03-13 12:12:43.000000000 +0000
+++ src/colormap.h
@@ -6,9 +6,10 @@
 #include "linalg.h"
 
 #include "memory.h"
+#ifndef Q_MOC_RUN
 #include <boost/filesystem.hpp>
 #include <boost/property_tree/ptree.hpp>
-
+#endif
 namespace fs = boost::filesystem;
 
 enum class RenderColor {
