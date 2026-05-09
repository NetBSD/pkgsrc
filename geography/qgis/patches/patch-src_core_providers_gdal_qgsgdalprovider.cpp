$NetBSD: patch-src_core_providers_gdal_qgsgdalprovider.cpp,v 1.1 2026/05/09 12:01:07 gdt Exp $

--- src/core/providers/gdal/qgsgdalprovider.cpp.orig	2026-04-03 12:00:51.000000000 +0000
+++ src/core/providers/gdal/qgsgdalprovider.cpp
@@ -517,7 +517,7 @@ void QgsGdalProvider::loadMetadata()
     // read ESRI FileGeodatabase/Personal Geodatabase layer metadata
     // (This branch is only possible on GDAL 3.7+, in earlier releases there was
     // no raster OpenFileGDB driver)
-    if ( char **GDALmetadata = GDALGetMetadata( mGdalDataset, "xml:documentation" ) )
+    if ( CSLConstList GDALmetadata = GDALGetMetadata( mGdalDataset, "xml:documentation" ) )
     {
       const QString metadata( GDALmetadata[0] );
       if ( !metadata.isEmpty() )
@@ -565,7 +565,7 @@ QString QgsGdalProvider::htmlMetadata() 
   for ( int i = 1; i <= GDALGetRasterCount( dsForMetadata ); ++i )
   {
     GDALRasterBandH gdalBand = GDALGetRasterBand( dsForMetadata, i );
-    char **GDALmetadata = GDALGetMetadata( gdalBand, nullptr );
+    CSLConstList GDALmetadata = GDALGetMetadata( gdalBand, nullptr );
     myMetadata += QStringLiteral( "<tr><td class=\"highlight\">" ) + tr( "Band %1" ).arg( i ) + QStringLiteral( "</td><td>" );
     if ( GDALmetadata )
     {
@@ -596,7 +596,7 @@ QString QgsGdalProvider::htmlMetadata() 
     myMetadata += tr( "Mask band (exposed as alpha band)" ) + QStringLiteral( "<br />\n" );
   }
 
-  char **GDALmetadata = GDALGetMetadata( dsForMetadata, nullptr );
+  CSLConstList GDALmetadata = GDALGetMetadata( dsForMetadata, nullptr );
   if ( GDALmetadata )
   {
     QStringList metadata = QgsOgrUtils::cStringListToQStringList( GDALmetadata );
@@ -1304,7 +1304,7 @@ QString QgsGdalProvider::generateBandNam
 
   if ( mDriverName == QLatin1String( "netCDF" ) || mDriverName == QLatin1String( "GTiff" ) )
   {
-    char **GDALmetadata = GDALGetMetadata( mGdalDataset, nullptr );
+    CSLConstList GDALmetadata = GDALGetMetadata( mGdalDataset, nullptr );
     if ( GDALmetadata )
     {
       QStringList metadata = QgsOgrUtils::cStringListToQStringList( GDALmetadata );
@@ -1847,7 +1847,7 @@ QList<QgsProviderSublayerDetails> QgsGda
 
   QList<QgsProviderSublayerDetails> res;
 
-  char **metadata = GDALGetMetadata( dataset, "SUBDATASETS" );
+  CSLConstList metadata = GDALGetMetadata( dataset, "SUBDATASETS" );
 
   QVariantMap uriParts = decodeGdalUri( baseUri );
   const QString datasetPath = uriParts.value( QStringLiteral( "path" ) ).toString();
