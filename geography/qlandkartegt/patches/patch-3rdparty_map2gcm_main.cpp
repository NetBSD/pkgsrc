$NetBSD: patch-3rdparty_map2gcm_main.cpp,v 1.1 2013/05/23 15:03:51 joerg Exp $

--- 3rdparty/map2gcm/main.cpp.orig	2013-05-23 14:10:57.000000000 +0000
+++ 3rdparty/map2gcm/main.cpp
@@ -84,7 +84,7 @@ struct file_t
         if(pj) pj_free(pj);
     }
 
-    bool operator<(const file_t& other)
+    bool operator<(const file_t& other) const
     {
         return (xscale < other.xscale);
     }
