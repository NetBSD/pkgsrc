$NetBSD: patch-src_utils_dumplibs.cpp,v 1.2 2025/04/25 08:12:38 wiz Exp $

Fix build with libxml2 2.12.
https://gitlab.com/manaplus/manaplus/-/issues/33

--- src/utils/dumplibs.cpp.orig	2021-01-27 20:14:00.000000000 +0000
+++ src/utils/dumplibs.cpp
@@ -140,9 +140,7 @@ void dumpLibs()
     LIBXML_TEST_VERSION
 #endif  // LIBXML_TEST_VERSION
 #ifdef ENABLE_LIBXML
-    const char **xmlVersion = __xmlParserVersion();
-    if (xmlVersion != nullptr)
-        logger->log(" libxml2: %s", *xmlVersion);
+    logger->log(" libxml2: %s", xmlParserVersion);
 #endif  // ENABLE_LIBXML
 #ifdef USE_SDL2
     SDL_version sdlVersion;
@@ -161,11 +159,11 @@ void dumpLibs()
 
     compareVersions("zLib", ZLIB_VERSION, zlibVersion());
 #ifdef ENABLE_LIBXML
-    if (xmlVersion != nullptr)
+    if (xmlParserVersion != nullptr)
     {
         compareVersions("libxml2",
             LIBXML_VERSION_STRING LIBXML_VERSION_EXTRA,
-            *xmlVersion);
+            xmlParserVersion);
     }
 #endif  // ENABLE_LIBXML
 #ifdef USE_SDL2
