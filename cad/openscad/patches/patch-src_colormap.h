$NetBSD: patch-src_colormap.h,v 1.1 2016/09/01 19:53:36 plunky Exp $

the Qt4 moc has some difficulty parsing in the boost headers. Apply
the workaround from https://bugreports.qt.io/browse/QTBUG-22829

--- src/colormap.h.orig	2016-09-01 12:19:29.305274482 +0000
+++ src/colormap.h
@@ -5,9 +5,11 @@
 #include <list>
 #include "linalg.h"
 
+#ifndef Q_MOC_RUN
 #include <boost/shared_ptr.hpp>
 #include <boost/filesystem.hpp>
 #include <boost/property_tree/ptree.hpp>
+#endif
 
 namespace fs = boost::filesystem;
 
