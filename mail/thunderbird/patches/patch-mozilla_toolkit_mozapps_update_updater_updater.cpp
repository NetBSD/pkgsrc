$NetBSD: patch-mozilla_toolkit_mozapps_update_updater_updater.cpp,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/toolkit/mozapps/update/updater/updater.cpp.orig	2013-10-23 22:09:20.000000000 +0000
+++ mozilla/toolkit/mozapps/update/updater/updater.cpp
@@ -127,7 +127,10 @@ static bool sUseHardLinks = true;
 // declare it here to avoid including that entire header file.
 #define BZ2_CRC32TABLE_UNDECLARED
 
-#if MOZ_IS_GCC
+#if defined(__clang__)
+extern "C"  __attribute__((visibility("default"))) unsigned int BZ2_crc32Table[256];
+#undef BZ2_CRC32TABLE_UNDECLARED
+#elif MOZ_IS_GCC
 #if MOZ_GCC_VERSION_AT_LEAST(3, 3, 0)
 extern "C"  __attribute__((visibility("default"))) unsigned int BZ2_crc32Table[256];
 #undef BZ2_CRC32TABLE_UNDECLARED
