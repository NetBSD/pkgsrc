$NetBSD: patch-src_core_qgsogrutils.h,v 1.1 2026/05/09 12:01:07 gdt Exp $

--- src/core/qgsogrutils.h.orig	2026-04-03 12:00:51.000000000 +0000
+++ src/core/qgsogrutils.h
@@ -312,7 +312,7 @@ class CORE_EXPORT QgsOgrUtils
      *
      * \since QGIS 3.2
      */
-    static QStringList cStringListToQStringList( char **stringList );
+    static QStringList cStringListToQStringList( const char *const *stringList );
 
     /**
      * Converts a OGRwkbGeometryType to QgsWkbTypes::Type
