$NetBSD: patch-src_core_providers_ogr_qgsogrprovidermetadata.cpp,v 1.1 2026/05/09 12:01:07 gdt Exp $

--- src/core/providers/ogr/qgsogrprovidermetadata.cpp.orig	2026-04-03 12:00:51.000000000 +0000
+++ src/core/providers/ogr/qgsogrprovidermetadata.cpp
@@ -103,7 +103,7 @@ bool QgsOgrProviderMetadata::createDatab
     return false;
   }
 
-  char **metadata = GDALGetMetadata( poDriver, nullptr );
+  CSLConstList metadata = GDALGetMetadata( poDriver, nullptr );
 
   if ( !CSLFetchBoolean( metadata, GDAL_DCAP_VECTOR, false )
        || !CSLFetchBoolean( metadata, GDAL_DCAP_CREATE, false ) )
