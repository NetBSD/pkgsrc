$NetBSD: patch-src_Utilities_Set.h,v 1.1 2012/12/22 20:01:45 joerg Exp $

--- src/Utilities/Set.h.orig	2012-12-22 19:04:37.000000000 +0000
+++ src/Utilities/Set.h
@@ -50,7 +50,7 @@ namespace Utilities
 
         bool contains(const T& x) const
         {
-            return count(x) > 0;
+            return this->count(x) > 0;
         }
 
         Set<T>& operator+=(const Set<T>& other);
