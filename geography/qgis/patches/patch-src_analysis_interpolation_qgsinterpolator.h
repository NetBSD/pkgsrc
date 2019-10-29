$NetBSD: patch-src_analysis_interpolation_qgsinterpolator.h,v 1.1 2019/10/29 19:30:11 bouyer Exp $

--- src/analysis/interpolation/qgsinterpolator.h.orig	2019-10-28 16:22:37.673002396 +0100
+++ src/analysis/interpolation/qgsinterpolator.h	2019-10-28 16:22:51.870493221 +0100
@@ -19,6 +19,7 @@
 #define QGSINTERPOLATOR_H
 
 #include <QVector>
+#include <QList>
 #include "qgis_sip.h"
 #include "qgis_analysis.h"
 
