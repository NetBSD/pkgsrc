$NetBSD: patch-include_lucene++_Set.h,v 1.1 2025/10/16 15:01:52 adam Exp $

Fix compilation with clang-17.
https://github.com/luceneplusplus/LucenePlusPlus/pull/213

--- include/lucene++/Set.h.orig	2025-10-16 14:57:03.550906159 +0000
+++ include/lucene++/Set.h
@@ -108,7 +108,7 @@ public:
     }
 
     void swap(this_type& other) {
-        setContainer.swap(other->setContainer);
+        setContainer.swap(other.setContainer);
     }
 
     operator bool() const {
