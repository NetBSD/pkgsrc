$NetBSD: patch-external_mdal_frmts_mdal__gdal.cpp,v 1.1 2026/05/09 12:01:07 gdt Exp $

This file, and all of

  patch-external_mdal_frmts_mdal__gdal.cpp
  patch-src_analysis_processing_qgsalgorithmimportphotos.cpp
  patch-src_core_providers_gdal_qgsgdalprovider.cpp
  patch-src_core_providers_ogr_qgsogrproviderconnection.cpp
  patch-src_core_providers_ogr_qgsogrprovidermetadata.cpp
  patch-src_core_qgsgdalutils.cpp
  patch-src_core_qgsogrutils.cpp
  patch-src_core_qgsogrutils.h
  patch-src_core_qgsvectorfilewriter.cpp
  patch-src_core_raster_qgsrasterfilewriter.cpp

are a cherry-pick of

  https://github.com/qgis/QGIS/pull/66017/
  
to fix the build with gdal 3.13.0.

--- external/mdal/frmts/mdal_gdal.cpp.orig	2026-04-03 12:00:51.000000000 +0000
+++ external/mdal/frmts/mdal_gdal.cpp
@@ -175,8 +175,7 @@ double MDAL::DriverGdal::parseMetadataTi
 MDAL::DriverGdal::metadata_hash MDAL::DriverGdal::parseMetadata( GDALMajorObjectH gdalObject, const char *pszDomain /* = 0 */ )
 {
   MDAL::DriverGdal::metadata_hash meta;
-  char **GDALmetadata = nullptr;
-  GDALmetadata = GDALGetMetadata( gdalObject, pszDomain );
+  CSLConstList GDALmetadata = GDALGetMetadata( gdalObject, pszDomain );
 
   if ( GDALmetadata )
   {
