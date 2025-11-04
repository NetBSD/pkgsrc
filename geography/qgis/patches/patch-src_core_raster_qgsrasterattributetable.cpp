$NetBSD: patch-src_core_raster_qgsrasterattributetable.cpp,v 1.2 2025/11/04 20:33:19 gdt Exp $

Remediate bare isnan usage.

Fixed on master, to be backported to 3.44:
  https://github.com/qgis/QGIS/pull/63803

--- src/core/raster/qgsrasterattributetable.cpp.orig	2024-01-26 14:03:42.143505820 +0000
+++ src/core/raster/qgsrasterattributetable.cpp
@@ -1359,7 +1359,7 @@ QgsGradientColorRamp QgsRasterAttributeT
       if ( range != 0 )
       {
 
-        if ( ! isnan( min ) && ! isnan( max ) )
+        if ( ! std::isnan( min ) && ! std::isnan( max ) )
         {
           const QList<QVariantList> dataCopy( orderedRows() );
 
