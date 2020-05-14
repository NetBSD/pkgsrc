$NetBSD: patch-ext_glslang_glslang_Include_PoolAlloc.h,v 1.1 2020/05/14 19:34:44 joerg Exp $

setAllocator violates the contract of TPoolAllocator, so drop it.

--- ext/glslang/glslang/Include/PoolAlloc.h.orig	2020-05-13 18:03:35.137900371 +0000
+++ ext/glslang/glslang/Include/PoolAlloc.h
@@ -304,7 +304,7 @@ public:
     size_type max_size() const { return static_cast<size_type>(-1) / sizeof(T); }
     size_type max_size(int size) const { return static_cast<size_type>(-1) / size; }
 
-    void setAllocator(TPoolAllocator* a) { allocator = *a; }
+    //void setAllocator(TPoolAllocator* a) { allocator = *a; }
     TPoolAllocator& getAllocator() const { return allocator; }
 
 protected:
