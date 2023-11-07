$NetBSD: patch-src_apps_ocioarchive_main.cpp,v 1.1 2023/11/07 20:29:25 nros Exp $

Fix build with minizip-ng version 4 and above
based on upstream patch:
https://github.com/AcademySoftwareFoundation/OpenColorIO/commit/bdc4cd124140f997cdec1c5d7db72b1550fe7eac

--- src/apps/ocioarchive/main.cpp.orig	2023-01-06 02:05:59.000000000 +0000
+++ src/apps/ocioarchive/main.cpp
@@ -235,7 +235,7 @@ int main(int argc, const char **argv)
         }
 
         std::string path = args[0];
-        mz_zip_reader_create(&reader);
+        reader = mz_zip_reader_create();
         struct tm tmu_date;
         
         err = mz_zip_reader_open_file(reader, path.c_str());
