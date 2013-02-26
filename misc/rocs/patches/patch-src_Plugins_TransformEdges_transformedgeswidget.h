$NetBSD: patch-src_Plugins_TransformEdges_transformedgeswidget.h,v 1.1 2013/02/26 23:37:32 joerg Exp $

--- src/Plugins/TransformEdges/transformedgeswidget.h.orig	2011-09-26 09:45:24.000000000 +0000
+++ src/Plugins/TransformEdges/transformedgeswidget.h
@@ -22,8 +22,10 @@
 #include <QWidget>
 #include <KDialog>
 
+#ifndef Q_MOC_RUN
 #include <boost/graph/adjacency_list.hpp>
 #include <boost/graph/topology.hpp>
+#endif
 
 #include "Rocs_Typedefs.h"
 
