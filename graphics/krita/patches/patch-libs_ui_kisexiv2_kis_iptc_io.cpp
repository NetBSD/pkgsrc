$NetBSD: patch-libs_ui_kisexiv2_kis_iptc_io.cpp,v 1.1 2023/07/06 23:27:01 mrg Exp $

Build with exiv2 0.28.

--- libs/ui/kisexiv2/kis_iptc_io.cpp.orig	2021-08-24 00:56:28.000000000 -0700
+++ libs/ui/kisexiv2/kis_iptc_io.cpp	2023-07-06 13:42:14.791576472 -0700
@@ -121,7 +121,7 @@
                 if (v && v->typeId() != Exiv2::invalidTypeId) {
                     iptcData.add(iptcKey, v);
                 }
-            } catch (Exiv2::AnyError& e) {
+            } catch (Exiv2::Error& e) {
                 dbgMetaData << "exiv error " << e.what();
             }
         }
@@ -139,7 +139,7 @@
         header.append(photoshopBimId_);
         header.append(photoshopIptc_);
         header.append(QByteArray(2, 0));
-        qint32 size = rawData.size_;
+        qint32 size = rawData.size();
         QByteArray sizeArray(4, 0);
         sizeArray[0] = (char)((size & 0xff000000) >> 24);
         sizeArray[1] = (char)((size & 0x00ff0000) >> 16);
@@ -149,7 +149,7 @@
         ioDevice->write(header);
     }
 
-    ioDevice->write((const char*) rawData.pData_, rawData.size_);
+    ioDevice->write((const char*) rawData.c_str(), rawData.size());
     ioDevice->close();
     return true;
 }
