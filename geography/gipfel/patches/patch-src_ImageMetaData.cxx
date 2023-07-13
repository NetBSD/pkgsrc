$NetBSD: patch-src_ImageMetaData.cxx,v 1.2 2023/07/13 09:31:07 wiz Exp $

Fix build with exiv2 0.28.0

--- src/ImageMetaData.cxx.orig	2010-03-11 12:36:30.000000000 +0000
+++ src/ImageMetaData.cxx
@@ -19,6 +19,8 @@
 
 #include <exiv2/image.hpp>
 #include <exiv2/exif.hpp>
+#include <exiv2/error.hpp>
+#include <exiv2/version.hpp>
 
 #include "../config.h"
 #include "ImageMetaData.H"
@@ -102,12 +104,16 @@ exifSetCoordinate(double *destVal, Exiv2
 
 int
 ImageMetaData::load_image_exif(char *name) {
+#if EXIV2_TEST_VERSION(0,28,0)
+	Exiv2::Image::UniquePtr image;
+#else
 	Exiv2::Image::AutoPtr image;
+#endif
 
 	try {
 		image = Exiv2::ImageFactory::open(name);
 		image->readMetadata();
-	} catch (Exiv2::Error error) {
+	} catch (Exiv2::Error &error) {
 		fprintf(stderr, "Error reading metadata\n");
 		return 1;
 	}
@@ -134,19 +140,19 @@ ImageMetaData::load_image_exif(char *nam
 			_model = strdup(pos->toString().c_str());
 	}
 
-    if (isnan(_focal_length))
+    if (std::isnan(_focal_length))
 		exifSetValue(&_focal_length, &exifData, "Exif.Photo.FocalLength");
 
-    if (isnan(_focal_length_35mm))
+    if (std::isnan(_focal_length_35mm))
 		exifSetValue(&_focal_length_35mm, &exifData, "Exif.Photo.FocalLengthIn35mmFilm");
 
-    if (isnan(_longitude))
+    if (std::isnan(_longitude))
 		exifSetCoordinate(&_longitude, &exifData, "Exif.GPSInfo.GPSLongitude");
 
-    if (isnan(_latitude))
+    if (std::isnan(_latitude))
 		exifSetCoordinate(&_latitude, &exifData, "Exif.GPSInfo.GPSLatitude");
 
-    if (isnan(_height))
+    if (std::isnan(_height))
 		exifSetValue(&_height, &exifData, "Exif.GPSInfo.GPSAltitude");
 
     return 0;
@@ -170,12 +176,16 @@ ImageMetaData::load_image_jpgcom(char *n
     double lo, la, he, dir, ni, ti, fr, k0, k1, x0 = 0.0;
     int pt = 0;
     int n, ret = 1;
+#if EXIV2_TEST_VERSION(0,28,0)
+	Exiv2::Image::UniquePtr image;
+#else
 	Exiv2::Image::AutoPtr image;
+#endif
 
 	try {
 		image = Exiv2::ImageFactory::open(name);
 		image->readMetadata();
-	} catch (Exiv2::Error error) {
+	} catch (Exiv2::Error &error) {
 		fprintf(stderr, "Error reading metadata\n");
 		return 1;
 	}
@@ -245,7 +255,11 @@ ImageMetaData::save_image_jpgcom(char *i
 
 	close(in_fd);
 
+#if EXIV2_TEST_VERSION(0,28,0)
+    Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(tmpname);
+#else
     Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(tmpname);
+#endif
     if (!image.get())
 		err++;
 
@@ -267,7 +281,7 @@ ImageMetaData::save_image_jpgcom(char *i
 
 	try {
 		image->writeMetadata();
-	} catch (Exiv2::Error error) {
+	} catch (Exiv2::Error &error) {
 		fprintf(stderr, "Error writing metadata\n");
 		err++;
 	}
