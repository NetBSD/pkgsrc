$NetBSD: patch-plugins_impex_jpeg_kis_jpeg_converter.cc,v 1.1 2023/07/06 23:27:01 mrg Exp $

Build with exiv2 0.28.

--- plugins/impex/jpeg/kis_jpeg_converter.cc.orig	2021-08-24 00:56:28.000000000 -0700
+++ plugins/impex/jpeg/kis_jpeg_converter.cc	2023-07-06 15:12:17.582284622 -0700
@@ -33,6 +33,7 @@
 }
 
 #include <exiv2/jpgimage.hpp>
+#include <exiv2/photoshop.hpp>
 
 #include <QFile>
 #include <QBuffer>
@@ -389,7 +390,7 @@
             uint32_t sizeHdr = 0;
             // Find actual Iptc data within the APP13 segment
             if (!Exiv2::Photoshop::locateIptcIrb((Exiv2::byte*)(marker->data + 14),
-                                                 marker->data_length - 14, &record, &sizeHdr, &sizeIptc)) {
+                                                 marker->data_length - 14, &record, sizeHdr, sizeIptc)) {
                 if (sizeIptc) {
                     // Decode the IPTC data
                     QByteArray byteArray((const char*)(record + sizeHdr), sizeIptc);
