$NetBSD: patch-src_core_raster_qgsrasterfilewriter.cpp,v 1.1 2026/05/09 12:01:07 gdt Exp $

--- src/core/raster/qgsrasterfilewriter.cpp.orig	2026-04-03 12:00:51.000000000 +0000
+++ src/core/raster/qgsrasterfilewriter.cpp
@@ -1090,7 +1090,7 @@ QString QgsRasterFileWriter::driverForEx
     GDALDriverH drv = GDALGetDriver( i );
     if ( drv )
     {
-      char **driverMetadata = GDALGetMetadata( drv, nullptr );
+      CSLConstList driverMetadata = GDALGetMetadata( drv, nullptr );
       if ( CSLFetchBoolean( driverMetadata, GDAL_DCAP_RASTER, false ) )
       {
         QString drvName = GDALGetDriverShortName( drv );
@@ -1113,7 +1113,7 @@ QStringList QgsRasterFileWriter::extensi
   GDALDriverH drv = GDALGetDriverByName( format.toLocal8Bit().data() );
   if ( drv )
   {
-    char **driverMetadata = GDALGetMetadata( drv, nullptr );
+    CSLConstList driverMetadata = GDALGetMetadata( drv, nullptr );
     if ( CSLFetchBoolean( driverMetadata, GDAL_DCAP_RASTER, false ) )
     {
       return QString( GDALGetMetadataItem( drv, GDAL_DMD_EXTENSIONS, nullptr ) ).split( ' ' );
