$NetBSD: patch-libs_ui_kisexiv2_kis__xmp__io.cpp,v 1.1 2019/07/17 00:39:57 nia Exp $

Fix building against exiv2-0.27

Upstream commit:
https://github.com/KDE/krita/commit/6b6758bb37da4997be36a7e2a839b07278160559.patch

--- libs/ui/kisexiv2/kis_xmp_io.cpp.orig	2018-09-26 12:18:03.000000000 +0000
+++ libs/ui/kisexiv2/kis_xmp_io.cpp
@@ -17,7 +17,6 @@
 #include "kis_xmp_io.h"
 
 #include <string>
-#include <exiv2/xmp.hpp>
 
 #include "kis_exiv2.h"
 
@@ -277,9 +276,8 @@ bool KisXMPIO::loadFrom(KisMetaData::Sto
                 const Exiv2::XmpArrayValue* xav = dynamic_cast<const Exiv2::XmpArrayValue*>(value.get());
                 Q_ASSERT(xav);
                 QList<KisMetaData::Value> array;
-                for (std::vector< std::string >::const_iterator it = xav->value_.begin();
-                        it != xav->value_.end(); ++it) {
-                    QString value = it->c_str();
+                for (int i = 0; i < xav->size(); ++i) {
+                    QString value = QString::fromStdString(xav->toString(i));
                     if (parser) {
                         array.push_back(parser->parse(value));
                     } else {
