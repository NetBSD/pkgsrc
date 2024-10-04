$NetBSD: patch-source_dynv_Types.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/dynv/Types.cpp.orig	2024-10-02 09:08:30.817212346 +0000
+++ source/dynv/Types.cpp
@@ -21,6 +21,7 @@
 #include "Color.h"
 #include <algorithm>
 #include <boost/endian/conversion.hpp>
+#include <boost/version.hpp>
 namespace dynv {
 namespace xml {
 bool serialize(std::ostream &stream, const Map &map, bool addRootElement = true);
