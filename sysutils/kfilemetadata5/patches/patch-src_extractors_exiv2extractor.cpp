$NetBSD: patch-src_extractors_exiv2extractor.cpp,v 1.1 2023/07/01 22:14:10 wiz Exp $

Fix build with exiv2 0.28.0.
https://invent.kde.org/frameworks/kfilemetadata/-/commit/6fcce03cfd85fffbe6d7701506de49c5987fdbe5

--- src/extractors/exiv2extractor.cpp.orig	2022-09-05 12:06:30.000000000 +0000
+++ src/extractors/exiv2extractor.cpp
@@ -75,7 +75,11 @@ QVariant toVariantDateTime(const Exiv2::
 QVariant toVariantLong(const Exiv2::Value& value)
 {
     if (value.typeId() == Exiv2::unsignedLong || value.typeId() == Exiv2::signedLong) {
+#if EXIV2_TEST_VERSION(0,28,0)
+        qlonglong val = value.toInt64();
+#else
         qlonglong val = value.toLong();
+#endif
         return QVariant(val);
     }
 
@@ -310,7 +314,11 @@ double Exiv2Extractor::fetchGpsAltitude(
         it = data.findKey(Exiv2::ExifKey("Exif.GPSInfo.GPSAltitudeRef"));
         if (it != data.end() && it->count() > 0 &&
             (it->value().typeId() == Exiv2::unsignedByte || it->value().typeId() == Exiv2::signedByte)) {
+#if EXIV2_TEST_VERSION(0,28,0)
+            auto altRef = it->value().toInt64();
+#else
             auto altRef = it->value().toLong();
+#endif
             if (altRef) {
                 alt = -1.0 * ratio.first / ratio.second;
             } else {
