$NetBSD: patch-src_hugin__base_panodata_Exiv2Helper.cpp,v 1.3 2023/07/19 07:17:47 wiz Exp $

Fix build with exiv2 0.28.

--- src/hugin_base/panodata/Exiv2Helper.cpp.orig	2019-05-15 15:30:47.000000000 +0000
+++ src/hugin_base/panodata/Exiv2Helper.cpp
@@ -40,7 +40,7 @@ namespace HuginBase
             Exiv2::ExifData::iterator itr = exifData.findKey(Exiv2::ExifKey(keyName));
             if (itr != exifData.end() && itr->count())
             {
-                value = itr->toLong();
+                value = itr->toInt64();
                 return true;
             }
             else
@@ -165,7 +165,7 @@ namespace HuginBase
         {
             if(it!=exifData.end() && it->count())
             {
-                return it->toLong();
+                return it->toInt64();
             }
             return 0;
         };
