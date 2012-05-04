$NetBSD: patch-frmts_netcdf_netcdfdataset.cpp,v 1.1 2012/05/04 13:27:23 hans Exp $

--- frmts/netcdf/netcdfdataset.cpp.orig	2012-01-04 08:03:37.000000000 +0100
+++ frmts/netcdf/netcdfdataset.cpp	2012-05-04 15:08:15.080833521 +0200
@@ -962,7 +962,7 @@ void  netCDFRasterBand::CheckValidData (
             /* check for nodata and nan */
             if ( CPLIsEqual( (double) ((T *)pImage)[i], dfNoDataValue ) )
                 continue;
-            if( bCheckIsNan && CPLIsNan( ( (T *) pImage)[i] ) ) {
+            if( bCheckIsNan && CPLIsNan( (double) ( (T *) pImage)[i] ) ) {
                 ( (T *)pImage )[i] = (T)dfNoDataValue;
                 continue;
             }
