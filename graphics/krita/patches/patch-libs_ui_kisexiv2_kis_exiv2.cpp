$NetBSD: patch-libs_ui_kisexiv2_kis_exiv2.cpp,v 1.1 2023/07/06 23:27:01 mrg Exp $

Build with exiv2 0.28.

--- libs/ui/kisexiv2/kis_exiv2.cpp.orig	2021-08-24 00:56:28.000000000 -0700
+++ libs/ui/kisexiv2/kis_exiv2.cpp	2023-07-06 13:23:55.815213204 -0700
@@ -30,7 +30,7 @@
 // ---- Generic conversion functions ---- //
 
 // Convert an exiv value to a KisMetaData value
-KisMetaData::Value exivValueToKMDValue(const Exiv2::Value::AutoPtr value, bool forceSeq, KisMetaData::Value::ValueType arrayType)
+KisMetaData::Value exivValueToKMDValue(const Exiv2::Value::UniquePtr value, bool forceSeq, KisMetaData::Value::ValueType arrayType)
 {
     switch (value->typeId()) {
     case Exiv2::signedByte:
@@ -51,11 +51,11 @@
     case Exiv2::signedShort:
     case Exiv2::signedLong: {
         if (value->count() == 1 && !forceSeq) {
-            return KisMetaData::Value((int)value->toLong());
+            return KisMetaData::Value((int)value->toInt64());
         } else {
             QList<KisMetaData::Value> array;
             for (int i = 0; i < value->count(); i++)
-                array.push_back(KisMetaData::Value((int)value->toLong(i)));
+                array.push_back(KisMetaData::Value((int)value->toInt64(i)));
             return KisMetaData::Value(array, arrayType);
         }
     }
