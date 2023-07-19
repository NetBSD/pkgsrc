$NetBSD: patch-src_Exif_ExifOperations.cpp,v 1.3 2023/07/19 08:05:51 wiz Exp $

Fix build with exiv2 0.28.
https://github.com/LuminanceHDR/LuminanceHDR/pull/273

--- src/Exif/ExifOperations.cpp.orig	2019-06-09 19:18:38.000000000 +0000
+++ src/Exif/ExifOperations.cpp
@@ -108,7 +108,7 @@ void copyExifData(const std::string &fro
 #endif
 
     try {
-        Exiv2::Image::AutoPtr sourceImage;
+        Exiv2::Image::UniquePtr sourceImage;
         Exiv2::ExifData srcExifData;
 
         if (!from.empty()) {
@@ -128,7 +128,7 @@ void copyExifData(const std::string &fro
         }
 
         // get destination exif data
-        Exiv2::Image::AutoPtr destinationImage = Exiv2::ImageFactory::open(to);
+        Exiv2::Image::UniquePtr destinationImage = Exiv2::ImageFactory::open(to);
 
         if (dontOverwrite) {
             // doesn't throw anything if it is empty
@@ -212,7 +212,7 @@ void copyExifData(const std::string &fro
             destinationImage->setExifData(srcExifData);
         }
         destinationImage->writeMetadata();
-    } catch (Exiv2::AnyError &e) {
+    } catch (Exiv2::Error &e) {
 #ifndef NDEBUG
         qDebug() << e.what();
 #endif
@@ -250,7 +250,7 @@ float obtain_avg_lum(const std::string& 
 {
     try
     {
-        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filename);
+        Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(filename);
         image->readMetadata();
         Exiv2::ExifData &exifData = image->exifData();
         if (exifData.empty())
@@ -329,7 +329,7 @@ allowed for ev computation purposes.
             return -1;
         }
     }
-    catch (Exiv2::AnyError& e)
+    catch (Exiv2::Error& e)
     {
         return -1;
     }
@@ -338,7 +338,7 @@ allowed for ev computation purposes.
 
 float getExposureTime(const std::string &filename) {
     try {
-        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filename);
+        Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(filename);
         image->readMetadata();
         Exiv2::ExifData &exifData = image->exifData();
         if (exifData.empty()) return -1;
@@ -374,14 +374,14 @@ float getExposureTime(const std::string 
         } else {
             return -1;
         }
-    } catch (Exiv2::AnyError &e) {
+    } catch (Exiv2::Error &e) {
         return -1;
     }
 }
 
 float getAverageLuminance(const std::string &filename) {
     try {
-        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filename);
+        Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(filename);
         image->readMetadata();
         Exiv2::ExifData &exifData = image->exifData();
 
@@ -403,7 +403,7 @@ float getAverageLuminance(const std::str
                   << std::endl;
 
         return -1.0;
-    } catch (Exiv2::AnyError &e) {
+    } catch (Exiv2::Error &e) {
         return -1.0;
     }
 }
