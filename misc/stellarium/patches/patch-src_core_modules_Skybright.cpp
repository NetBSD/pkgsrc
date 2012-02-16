--- src/core/modules/Skybright.cpp.orig	2011-07-02 15:22:18.000000000 +0200
+++ src/core/modules/Skybright.cpp	2011-11-01 17:14:24.676826514 +0100
@@ -29,6 +29,8 @@
 #include "Skybright.hpp"
 #include "StelUtils.hpp"
 
+#undef FS
+
 Skybright::Skybright() : SN(1.f)
 {
 	setDate(2003, 8, 0);
