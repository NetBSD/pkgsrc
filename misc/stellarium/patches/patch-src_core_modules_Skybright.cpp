$NetBSD: patch-src_core_modules_Skybright.cpp,v 1.2 2012/06/03 10:08:37 wiz Exp $

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
