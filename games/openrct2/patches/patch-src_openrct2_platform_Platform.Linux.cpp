$NetBSD: patch-src_openrct2_platform_Platform.Linux.cpp,v 1.3 2023/07/22 10:55:16 triaxx Exp $

Support pkgsrc.

--- src/openrct2/platform/Platform.Linux.cpp.orig	2020-08-15 19:13:50.000000000 +0000
+++ src/openrct2/platform/Platform.Linux.cpp
@@ -55,7 +55,7 @@ namespace Platform
     {
         static const utf8* searchLocations[] = {
             "./doc",
-            "/usr/share/doc/openrct2",
+            "@PREFIX@/share/doc/openrct2",
         };
         for (auto searchLocation : searchLocations)
         {
