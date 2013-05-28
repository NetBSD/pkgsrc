$NetBSD: patch-src_includes_LRUCache.h,v 1.1 2013/05/28 19:03:09 joerg Exp $

--- src/includes/LRUCache.h.orig	2013-05-28 17:02:59.000000000 +0000
+++ src/includes/LRUCache.h
@@ -60,7 +60,7 @@ public:
   {
   public:
     bool operator()(const NodeType *a,
-                    const NodeType *b)
+                    const NodeType *b) const
     {
       return a->key < b->key;
     }
