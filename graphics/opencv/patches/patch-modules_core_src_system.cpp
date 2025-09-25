$NetBSD: patch-modules_core_src_system.cpp,v 1.3 2025/09/25 10:32:36 adam Exp $

Avoid including all from configure as it contains references to work dir.

--- modules/core/src/system.cpp.orig	2025-04-22 09:32:49.970273357 +0000
+++ modules/core/src/system.cpp
@@ -1030,9 +1030,7 @@ int64 getTimestampNS()
 
 const String& getBuildInformation()
 {
-    static String build_info =
-#include "version_string.inc"
-    ;
+    static String build_info = "PkgSrc";
     return build_info;
 }
 
