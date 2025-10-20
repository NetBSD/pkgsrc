$NetBSD: patch-src_ImportExport_ImportExportGdal.cpp,v 1.1 2025/10/20 23:17:13 gdt Exp $

  - Const hygiene exposed by gdal 3.12.0.
  - Arguably srs release in OSGB workaround is a bug anyway.

https://github.com/openstreetmap/merkaartor/issues/314

--- src/ImportExport/ImportExportGdal.cpp.orig	2025-10-20 22:58:47.446184870 +0000
+++ src/ImportExport/ImportExportGdal.cpp
@@ -337,7 +337,7 @@ bool ImportExportGdal::importGDALDataset
     qDebug(lc_importExportGdal) << "Layers #" << poDS->GetLayerCount();
     OGRLayer  *poLayer = poDS->GetLayer(0);
 
-    OGRSpatialReference * theSrs = poLayer->GetSpatialRef(); // Note: Contrary to other OGR objects, the spatial ref must NOT be released by our code!
+    const OGRSpatialReference * theSrs = poLayer->GetSpatialRef(); // Note: Contrary to other OGR objects, the spatial ref must NOT be released by our code!
     toWGS84 = NULL;
 
     if (theSrs) {
@@ -351,7 +351,6 @@ bool ImportExportGdal::importGDALDataset
                 qDebug("GDAL: couldn't initialise EPSG:27700: %d: %s", ogrError, CPLGetLastErrorMsg());
                 the27700Srs->Release();
             } else {
-                theSrs->Release();
                 theSrs = the27700Srs;
             }
         }
@@ -390,7 +389,7 @@ bool ImportExportGdal::importGDALDataset
                 Feature* F = parseGeometry(aLayer, poGeometry);
                 if (F) {
                     for (int i=0; i<poFeature->GetFieldCount(); ++i) {
-                        OGRFieldDefn  *fd = poFeature->GetFieldDefnRef(i);
+                        const OGRFieldDefn  *fd = poFeature->GetFieldDefnRef(i);
                         QString k = QString::fromUtf8(fd->GetNameRef());
                         if (k == "osm_id") {
                             F->setId(IFeature::FId(F->getType(), (qint64)poFeature->GetFieldAsDouble(i)));
