$NetBSD: patch-src_Libpfs_exif_exifdata.cpp,v 1.1 2023/07/19 08:05:51 wiz Exp $

Fix build with exiv2 0.28.
https://github.com/LuminanceHDR/LuminanceHDR/pull/273

--- src/Libpfs/exif/exifdata.cpp.orig	2019-06-09 19:18:38.000000000 +0000
+++ src/Libpfs/exif/exifdata.cpp
@@ -52,7 +52,7 @@ ExifData::ExifData(const std::string &fi
 void ExifData::fromFile(const std::string &filename) {
     reset();
     try {
-        ::Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filename);
+        ::Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(filename);
         image->readMetadata();
         ::Exiv2::ExifData &exifData = image->exifData();
 
@@ -121,7 +121,7 @@ void ExifData::fromFile(const std::strin
          */
         if ((it = exifData.findKey(Exiv2::ExifKey("Exif.Image.Orientation"))) !=
             exifData.end()) {
-            long rotation = it->toLong();
+            long rotation = it->toInt64();
             switch (rotation) {
                 case 3:
                     m_orientation = 180;
@@ -134,7 +134,7 @@ void ExifData::fromFile(const std::strin
                     break;
             }
         }
-    } catch (Exiv2::AnyError &e) {
+    } catch (Exiv2::Error &e) {
         return;
     }
 }
