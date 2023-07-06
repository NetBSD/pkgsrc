$NetBSD: patch-libs_ui_kisexiv2_kis_exiv2.h,v 1.1 2023/07/06 23:27:01 mrg Exp $

Build with exiv2 0.28.

--- libs/ui/kisexiv2/kis_exiv2.h.orig	2021-08-24 00:56:28.000000000 -0700
+++ libs/ui/kisexiv2/kis_exiv2.h	2023-07-06 13:21:06.245580233 -0700
@@ -25,7 +25,7 @@
 #include "kritaui_export.h"
 
 /// Convert an exiv value to a KisMetaData value
-KisMetaData::Value exivValueToKMDValue(const Exiv2::Value::AutoPtr value, bool forceSeq, KisMetaData::Value::ValueType arrayType = KisMetaData::Value::UnorderedArray);
+KisMetaData::Value exivValueToKMDValue(const Exiv2::Value::UniquePtr value, bool forceSeq, KisMetaData::Value::ValueType arrayType = KisMetaData::Value::UnorderedArray);
 
 /// Convert a KisMetaData to an Exiv value
 Exiv2::Value* kmdValueToExivValue(const KisMetaData::Value& value, Exiv2::TypeId type);
