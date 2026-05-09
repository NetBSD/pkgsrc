$NetBSD: patch-src_core_providers_ogr_qgsogrproviderconnection.cpp,v 1.1 2026/05/09 12:01:07 gdt Exp $

--- src/core/providers/ogr/qgsogrproviderconnection.cpp.orig	2026-04-03 12:00:51.000000000 +0000
+++ src/core/providers/ogr/qgsogrproviderconnection.cpp
@@ -419,7 +419,7 @@ void QgsOgrProviderConnection::setDefaul
   mGeometryColumnCapabilities |= GeometryColumnCapability::SinglePolygon;
 #endif
 
-  char **driverMetadata = GDALGetMetadata( hDriver, nullptr );
+  CSLConstList driverMetadata = GDALGetMetadata( hDriver, nullptr );
 
 #if GDAL_VERSION_NUM >= GDAL_COMPUTE_VERSION(3,6,0)
   if ( CSLFetchBoolean( driverMetadata, GDAL_DCAP_Z_GEOMETRIES, false ) )
