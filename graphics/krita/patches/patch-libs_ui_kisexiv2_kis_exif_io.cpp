$NetBSD: patch-libs_ui_kisexiv2_kis_exif_io.cpp,v 1.1 2023/07/06 23:27:01 mrg Exp $

Build with exiv2 0.28.

--- libs/ui/kisexiv2/kis_exif_io.cpp.orig	2021-08-24 00:56:28.000000000 -0700
+++ libs/ui/kisexiv2/kis_exif_io.cpp	2023-07-06 13:28:20.995859764 -0700
@@ -46,7 +46,7 @@
 // ---- Exception conversion functions ---- //
 
 // convert ExifVersion and FlashpixVersion to a KisMetaData value
-KisMetaData::Value exifVersionToKMDValue(const Exiv2::Value::AutoPtr value)
+KisMetaData::Value exifVersionToKMDValue(const Exiv2::Value::UniquePtr value)
 {
     const Exiv2::DataValue* dvalue = dynamic_cast<const Exiv2::DataValue*>(&*value);
     if (dvalue) {
@@ -71,7 +71,7 @@
 }
 
 // Convert an exif array of integer string to a KisMetaData array of integer
-KisMetaData::Value exifArrayToKMDIntOrderedArray(const Exiv2::Value::AutoPtr value)
+KisMetaData::Value exifArrayToKMDIntOrderedArray(const Exiv2::Value::UniquePtr value)
 {
     QList<KisMetaData::Value> v;
     const Exiv2::DataValue* dvalue = dynamic_cast<const Exiv2::DataValue*>(&*value);
@@ -103,7 +103,7 @@
     return new Exiv2::DataValue((const Exiv2::byte*)s.data(), s.size());
 }
 
-QDateTime exivValueToDateTime(const Exiv2::Value::AutoPtr value)
+QDateTime exivValueToDateTime(const Exiv2::Value::UniquePtr value)
 {
     return QDateTime::fromString(value->toString().c_str(), Qt::ISODate);
 }
@@ -138,7 +138,7 @@
 }
 
 
-KisMetaData::Value exifOECFToKMDOECFStructure(const Exiv2::Value::AutoPtr value, Exiv2::ByteOrder order)
+KisMetaData::Value exifOECFToKMDOECFStructure(const Exiv2::Value::UniquePtr value, Exiv2::ByteOrder order)
 {
     QMap<QString, KisMetaData::Value> oecfStructure;
     const Exiv2::DataValue* dvalue = dynamic_cast<const Exiv2::DataValue*>(&*value);
@@ -223,7 +223,7 @@
     return new Exiv2::DataValue((const Exiv2::byte*)array.data(), array.size());
 }
 
-KisMetaData::Value deviceSettingDescriptionExifToKMD(const Exiv2::Value::AutoPtr value)
+KisMetaData::Value deviceSettingDescriptionExifToKMD(const Exiv2::Value::UniquePtr value)
 {
     QMap<QString, KisMetaData::Value> deviceSettingStructure;
     QByteArray array;
@@ -279,7 +279,7 @@
     return new Exiv2::DataValue((const Exiv2::byte*)array.data(), array.size());
 }
 
-KisMetaData::Value cfaPatternExifToKMD(const Exiv2::Value::AutoPtr value, Exiv2::ByteOrder order)
+KisMetaData::Value cfaPatternExifToKMD(const Exiv2::Value::UniquePtr value, Exiv2::ByteOrder order)
 {
     QMap<QString, KisMetaData::Value> cfaPatternStructure;
     const Exiv2::DataValue* dvalue = dynamic_cast<const Exiv2::DataValue*>(&*value);
@@ -328,9 +328,9 @@
 
 // Read and write Flash //
 
-KisMetaData::Value flashExifToKMD(const Exiv2::Value::AutoPtr value)
+KisMetaData::Value flashExifToKMD(const Exiv2::Value::UniquePtr value)
 {
-    uint16_t v = value->toLong();
+    uint16_t v = value->toInt64();
     QMap<QString, KisMetaData::Value> flashStructure;
     bool fired = (v & 0x01);  // bit 1 is whether flash was fired or not
     flashStructure["Fired"] = QVariant(fired);
@@ -483,7 +483,7 @@
                     dbgMetaData << "No exif value was created for" << entry.qualifiedName() << " as" << exivKey;// << " of KMD value" << entry.value();
                 }
             }
-        } catch (Exiv2::AnyError& e) {
+        } catch (Exiv2::Error& e) {
             dbgMetaData << "exiv error " << e.what();
         }
     }
