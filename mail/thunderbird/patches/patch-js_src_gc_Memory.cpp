$NetBSD: patch-js_src_gc_Memory.cpp,v 1.2 2019/02/26 11:32:13 ryoon Exp $

--- js/src/gc/Memory.cpp.orig	2019-02-13 14:19:38.000000000 +0000
+++ js/src/gc/Memory.cpp
@@ -419,6 +419,7 @@ static inline void* MapMemoryAt(void* de
                                 off_t offset = 0) {
 
 #if defined(__ia64__) || defined(__aarch64__) ||  \
+    (defined(__sun) && defined(__x86_64__)) || \
     (defined(__sparc__) && defined(__arch64__) && \
      (defined(__NetBSD__) || defined(__linux__)))
   MOZ_ASSERT((0xffff800000000000ULL & (uintptr_t(desired) + length - 1)) == 0);
@@ -468,7 +469,8 @@ static inline void* MapMemory(size_t len
   }
   return region;
 #elif defined(__aarch64__) || \
-    (defined(__sparc__) && defined(__arch64__) && defined(__linux__))
+    (defined(__sparc__) && defined(__arch64__) && defined(__linux__)) || \
+    (defined(__sun) && defined(__x86_64__))
   /*
    * There might be similar virtual address issue on arm64 which depends on
    * hardware and kernel configurations. But the work around is slightly
