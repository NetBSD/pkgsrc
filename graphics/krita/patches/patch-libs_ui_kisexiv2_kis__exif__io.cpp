$NetBSD: patch-libs_ui_kisexiv2_kis__exif__io.cpp,v 1.1 2019/07/17 00:39:57 nia Exp $

Fix building against exiv2-0.27

Upstream commit:
https://github.com/KDE/krita/commit/6b6758bb37da4997be36a7e2a839b07278160559.patch

--- libs/ui/kisexiv2/kis_exif_io.cpp.orig	2018-09-26 12:18:03.000000000 +0000
+++ libs/ui/kisexiv2/kis_exif_io.cpp
@@ -438,11 +438,10 @@ bool KisExifIO::saveTo(KisMetaData::Stor
                     if (entry.value().asArray().size() > 0) {
                         creator = entry.value().asArray()[0];
                     }
-#if EXIV2_MAJOR_VERSION == 0 && EXIV2_MINOR_VERSION <= 20
+#if !EXIV2_TEST_VERSION(0,21,0)
                     v = kmdValueToExivValue(creator, Exiv2::ExifTags::tagType(exifKey.tag(), exifKey.ifdId()));
 #else
                     v = kmdValueToExivValue(creator, exifKey.defaultTypeId());
-
 #endif
                 } else if (exivKey == "Exif.Photo.OECF") {
                     v = kmdOECFStructureToExifOECF(entry.value());
@@ -456,13 +455,13 @@ bool KisExifIO::saveTo(KisMetaData::Stor
                     Q_ASSERT(entry.value().type() == KisMetaData::Value::LangArray);
                     QMap<QString, KisMetaData::Value> langArr = entry.value().asLangArray();
                     if (langArr.contains("x-default")) {
-#if EXIV2_MAJOR_VERSION == 0 && EXIV2_MINOR_VERSION <= 20
+#if !EXIV2_TEST_VERSION(0,21,0)
                         v = kmdValueToExivValue(langArr.value("x-default"), Exiv2::ExifTags::tagType(exifKey.tag(), exifKey.ifdId()));
 #else
                         v = kmdValueToExivValue(langArr.value("x-default"), exifKey.defaultTypeId());
 #endif
                     } else if (langArr.size() > 0) {
-#if EXIV2_MAJOR_VERSION == 0 && EXIV2_MINOR_VERSION <= 20
+#if !EXIV2_TEST_VERSION(0,21,0)
                         v = kmdValueToExivValue(langArr.begin().value(), Exiv2::ExifTags::tagType(exifKey.tag(), exifKey.ifdId()));
 #else
                         v = kmdValueToExivValue(langArr.begin().value(), exifKey.defaultTypeId());
@@ -470,7 +469,7 @@ bool KisExifIO::saveTo(KisMetaData::Stor
                     }
                 } else {
                     dbgMetaData << exifKey.tag();
-#if EXIV2_MAJOR_VERSION == 0 && EXIV2_MINOR_VERSION <= 20
+#if !EXIV2_TEST_VERSION(0,21,0)
                     v = kmdValueToExivValue(entry.value(), Exiv2::ExifTags::tagType(exifKey.tag(), exifKey.ifdId()));
 #else
                     v = kmdValueToExivValue(entry.value(), exifKey.defaultTypeId());
@@ -487,7 +486,7 @@ bool KisExifIO::saveTo(KisMetaData::Stor
             dbgMetaData << "exiv error " << e.what();
         }
     }
-#if EXIV2_MAJOR_VERSION == 0 && EXIV2_MINOR_VERSION <= 17
+#if !EXIV2_TEST_VERSION(0,18,0)
     Exiv2::DataBuf rawData = exifData.copy();
     ioDevice->write((const char*) rawData.pData_, rawData.size_);
 #else
@@ -514,7 +513,7 @@ bool KisExifIO::loadFrom(KisMetaData::St
     QByteArray arr = ioDevice->readAll();
     Exiv2::ExifData exifData;
     Exiv2::ByteOrder byteOrder;
-#if EXIV2_MAJOR_VERSION == 0 && EXIV2_MINOR_VERSION <= 17
+#if !EXIV2_TEST_VERSION(0,18,0)
     exifData.load((const Exiv2::byte*)arr.data(), arr.size());
     byteOrder = exifData.byteOrder();
 #else
@@ -529,7 +528,6 @@ bool KisExifIO::loadFrom(KisMetaData::St
         dbgKrita << "Received unknown exception trying to parse exiv data";
         return false;
     }
-
 #endif
     dbgMetaData << "Byte order = " << byteOrder << ppVar(Exiv2::bigEndian) << ppVar(Exiv2::littleEndian);
     dbgMetaData << "There are" << exifData.count() << " entries in the exif section";
