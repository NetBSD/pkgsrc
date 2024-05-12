$NetBSD: patch-src_core_raster_qgsrasterattributetable.cpp,v 1.1 2024/05/12 13:47:30 gdt Exp $

Remediate bare isnan usage.

Queried via qgis-developer@ on 20240126.

--- src/core/raster/qgsrasterattributetable.cpp.orig	2024-01-26 14:03:42.143505820 +0000
+++ src/core/raster/qgsrasterattributetable.cpp
@@ -1359,7 +1359,7 @@ QgsGradientColorRamp QgsRasterAttributeT
       if ( range != 0 )
       {
 
-        if ( ! isnan( min ) && ! isnan( max ) )
+        if ( ! std::isnan( min ) && ! std::isnan( max ) )
         {
           const QList<QVariantList> dataCopy( orderedRows() );
 
