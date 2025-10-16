$NetBSD: patch-include_lucene++_Collection.h,v 1.1 2025/10/16 15:01:52 adam Exp $

Fix compilation with clang-17.
https://github.com/luceneplusplus/LucenePlusPlus/pull/213

--- include/lucene++/Collection.h.orig	2025-10-16 14:56:08.117208074 +0000
+++ include/lucene++/Collection.h
@@ -167,7 +167,7 @@ public:
     }
 
     void swap(this_type& other) {
-        container.swap(other->container);
+        container.swap(other.container);
     }
 
     TYPE& operator[] (int32_t pos) {
