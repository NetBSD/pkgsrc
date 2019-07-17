$NetBSD: patch-libs_ui_kisexiv2_kis__iptc__io.cpp,v 1.1 2019/07/17 00:39:57 nia Exp $

Fix building against exiv2-0.27

Upstream commit:
https://github.com/KDE/krita/commit/6b6758bb37da4997be36a7e2a839b07278160559.patch

--- libs/ui/kisexiv2/kis_iptc_io.cpp.orig	2018-09-26 12:18:03.000000000 +0000
+++ libs/ui/kisexiv2/kis_iptc_io.cpp
@@ -126,7 +126,7 @@ bool KisIptcIO::saveTo(KisMetaData::Stor
             }
         }
     }
-#if EXIV2_MAJOR_VERSION == 0 && EXIV2_MINOR_VERSION <= 17
+#if !EXIV2_TEST_VERSION(0,18,0)
     Exiv2::DataBuf rawData = iptcData.copy();
 #else
     Exiv2::DataBuf rawData = Exiv2::IptcParser::encode(iptcData);
@@ -167,7 +167,7 @@ bool KisIptcIO::loadFrom(KisMetaData::St
     ioDevice->open(QIODevice::ReadOnly);
     QByteArray arr = ioDevice->readAll();
     Exiv2::IptcData iptcData;
-#if EXIV2_MAJOR_VERSION == 0 && EXIV2_MINOR_VERSION <= 17
+#if !EXIV2_TEST_VERSION(0,18,0)
     iptcData.load((const Exiv2::byte*)arr.data(), arr.size());
 #else
     Exiv2::IptcParser::decode(iptcData, (const Exiv2::byte*)arr.data(), arr.size());
