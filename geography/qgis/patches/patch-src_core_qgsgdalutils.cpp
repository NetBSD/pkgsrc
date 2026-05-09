$NetBSD: patch-src_core_qgsgdalutils.cpp,v 1.1 2026/05/09 12:01:07 gdt Exp $

--- src/core/qgsgdalutils.cpp.orig	2026-04-03 12:00:51.000000000 +0000
+++ src/core/qgsgdalutils.cpp
@@ -496,7 +496,7 @@ QString QgsGdalUtils::helpCreationOption
   if ( myGdalDriver )
   {
     // first report details and help page
-    char **GDALmetadata = GDALGetMetadata( myGdalDriver, nullptr );
+    CSLConstList GDALmetadata = GDALGetMetadata( myGdalDriver, nullptr );
     message += QLatin1String( "Format Details:\n" );
     message += QStringLiteral( "  Extension: %1\n" ).arg( CSLFetchNameValue( GDALmetadata, GDAL_DMD_EXTENSION ) );
     message += QStringLiteral( "  Short Name: %1" ).arg( GDALGetDriverShortName( myGdalDriver ) );
