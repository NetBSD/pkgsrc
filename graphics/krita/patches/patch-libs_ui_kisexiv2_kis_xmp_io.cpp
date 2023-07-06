$NetBSD: patch-libs_ui_kisexiv2_kis_xmp_io.cpp,v 1.1 2023/07/06 23:27:01 mrg Exp $

Build with exiv2 0.28.

--- libs/ui/kisexiv2/kis_xmp_io.cpp.orig	2021-08-24 00:56:28.000000000 -0700
+++ libs/ui/kisexiv2/kis_xmp_io.cpp	2023-07-06 13:21:06.244731108 -0700
@@ -244,7 +244,7 @@
                     Q_ASSERT(schema);
                 }
             }
-            const Exiv2::Value::AutoPtr value = it->getValue();
+            const Exiv2::Value::UniquePtr value = it->getValue();
 
             QString structName;
             int arrayIndex = -1;
