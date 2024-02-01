$NetBSD: patch-src_utils_dumplibs.cpp,v 1.1 2024/02/01 08:57:16 wiz Exp $

Fix build with libxml2 2.12.
https://gitlab.com/manaplus/manaplus/-/issues/33

--- src/utils/dumplibs.cpp.orig	2024-02-01 08:51:36.691968861 +0000
+++ src/utils/dumplibs.cpp
@@ -140,7 +140,7 @@ void dumpLibs()
     LIBXML_TEST_VERSION
 #endif  // LIBXML_TEST_VERSION
 #ifdef ENABLE_LIBXML
-    const char **xmlVersion = __xmlParserVersion();
+    const char * const *xmlVersion = __xmlParserVersion();
     if (xmlVersion != nullptr)
         logger->log(" libxml2: %s", *xmlVersion);
 #endif  // ENABLE_LIBXML
