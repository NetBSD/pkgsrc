$NetBSD: patch-libkexiv2_kexiv2exif.cpp,v 1.1 2019/11/02 13:51:12 maya Exp $

New exiv2 support.
From https://github.com/KDE/libkexiv2/commit/d1be9298c7f2b9c717cda154d41732f230ea13a6

--- libkexiv2/kexiv2exif.cpp.orig	2015-04-30 19:04:22.000000000 +0000
+++ libkexiv2/kexiv2exif.cpp
@@ -986,7 +986,12 @@ bool KExiv2::setTiffThumbnail(const QIma
 
         if (pos == d->exifMetadata().end() || pos->count() != 1 || pos->toLong() != 0)
         {
+
+#if EXIV2_TEST_VERSION(0,27,0)
+            throw Exiv2::Error(Exiv2::kerErrorMessage, "Exif.Image.NewSubfileType missing or not set as main image");
+#else
             throw Exiv2::Error(1, "Exif.Image.NewSubfileType missing or not set as main image");
+#endif
         }
 
         // Remove sub-IFD tags
