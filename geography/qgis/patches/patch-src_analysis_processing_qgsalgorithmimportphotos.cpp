$NetBSD: patch-src_analysis_processing_qgsalgorithmimportphotos.cpp,v 1.1 2026/05/09 12:01:07 gdt Exp $

--- src/analysis/processing/qgsalgorithmimportphotos.cpp.orig	2026-04-03 12:00:51.000000000 +0000
+++ src/analysis/processing/qgsalgorithmimportphotos.cpp
@@ -397,7 +397,7 @@ QVariantMap QgsImportPhotosAlgorithm::pr
       continue;
     }
 
-    char **GDALmetadata = GDALGetMetadata( hDS.get(), nullptr );
+    CSLConstList GDALmetadata = GDALGetMetadata( hDS.get(), nullptr );
     if ( !GDALmetadata )
     {
       GDALmetadata = GDALGetMetadata( hDS.get(), "EXIF" );
