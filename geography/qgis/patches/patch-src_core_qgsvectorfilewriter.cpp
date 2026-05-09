$NetBSD: patch-src_core_qgsvectorfilewriter.cpp,v 1.1 2026/05/09 12:01:07 gdt Exp $

--- src/core/qgsvectorfilewriter.cpp.orig	2026-04-03 12:00:51.000000000 +0000
+++ src/core/qgsvectorfilewriter.cpp
@@ -158,7 +158,7 @@ bool QgsVectorFileWriter::supportsFeatur
   if ( !gdalDriver )
     return false;
 
-  char **driverMetadata = GDALGetMetadata( gdalDriver, nullptr );
+  CSLConstList driverMetadata = GDALGetMetadata( gdalDriver, nullptr );
   if ( !driverMetadata )
     return false;
 
@@ -4187,7 +4187,7 @@ QString QgsVectorFileWriter::driverForEx
     GDALDriverH drv = GDALGetDriver( i );
     if ( drv )
     {
-      char **driverMetadata = GDALGetMetadata( drv, nullptr );
+      CSLConstList driverMetadata = GDALGetMetadata( drv, nullptr );
       if ( CSLFetchBoolean( driverMetadata, GDAL_DCAP_CREATE, false ) && CSLFetchBoolean( driverMetadata, GDAL_DCAP_VECTOR, false ) )
       {
         QString drvName = GDALGetDriverShortName( drv );
