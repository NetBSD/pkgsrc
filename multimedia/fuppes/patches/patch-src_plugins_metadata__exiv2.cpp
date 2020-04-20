$NetBSD: patch-src_plugins_metadata__exiv2.cpp,v 1.1 2020/04/20 00:42:07 joerg Exp $

--- src/plugins/metadata_exiv2.cpp.orig	2020-04-19 19:41:17.830620082 +0000
+++ src/plugins/metadata_exiv2.cpp
@@ -24,6 +24,7 @@
 
 #include "../../include/fuppes_plugin.h"
 
+#include <exiv2/error.hpp>
 #include <exiv2/image.hpp>
 #include <exiv2/exif.hpp>
 #include <exiv2/iptc.hpp>
