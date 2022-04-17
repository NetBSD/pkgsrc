$NetBSD: patch-storage_ndb_src_common_util_NdbSqlUtil.cpp,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- storage/ndb/src/common/util/NdbSqlUtil.cpp.orig	2021-09-14 09:08:08.000000000 +0000
+++ storage/ndb/src/common/util/NdbSqlUtil.cpp
@@ -393,7 +393,7 @@ NdbSqlUtil::cmpFloat(const void* info, c
   float v1, v2;
   memcpy(&v1, p1, 4);
   memcpy(&v2, p2, 4);
-  require(!isnan(v1) && !isnan(v2));
+  require(!std::isnan(v1) && !std::isnan(v2));
   if (v1 < v2)
     return -1;
   if (v1 > v2)
@@ -408,7 +408,7 @@ NdbSqlUtil::cmpDouble(const void* info, 
   double v1, v2;
   memcpy(&v1, p1, 8);
   memcpy(&v2, p2, 8);
-  require(!isnan(v1) && !isnan(v2));
+  require(!std::isnan(v1) && !std::isnan(v2));
   if (v1 < v2)
     return -1;
   if (v1 > v2)
