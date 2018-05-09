$NetBSD: patch-src_node__i18n.cc,v 1.1 2018/05/09 12:18:03 adam Exp $

Fix building with ICU 61.

--- src/node_i18n.cc.orig	2018-05-04 08:04:50.000000000 +0000
+++ src/node_i18n.cc
@@ -523,7 +523,7 @@ const char* GetVersion(const char* type,
   } else if (!strcmp(type, TYPE_UNICODE)) {
     return U_UNICODE_VERSION;
   } else if (!strcmp(type, TYPE_TZ)) {
-    return TimeZone::getTZDataVersion(*status);
+    return icu::TimeZone::getTZDataVersion(*status);
   } else if (!strcmp(type, TYPE_CLDR)) {
     UVersionInfo versionArray;
     ulocdata_getCLDRVersion(versionArray, status);
