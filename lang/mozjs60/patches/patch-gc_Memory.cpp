$NetBSD: patch-gc_Memory.cpp,v 1.1 2020/04/09 09:40:47 jperkin Exp $

Fix build on SunOS/x86_64.

--- gc/Memory.cpp.orig	2019-07-01 09:07:41.000000000 +0000
+++ gc/Memory.cpp
@@ -419,6 +419,7 @@ static inline void* MapMemoryAt(void* de
                                 off_t offset = 0) {
 
 #if defined(__ia64__) || defined(__aarch64__) ||  \
+    (defined(__sun) && defined(__x86_64__)) ||     \
     (defined(__sparc__) && defined(__arch64__) && \
      (defined(__NetBSD__) || defined(__linux__)))
   MOZ_ASSERT((0xffff800000000000ULL & (uintptr_t(desired) + length - 1)) == 0);
@@ -468,6 +469,7 @@ static inline void* MapMemory(size_t len
   }
   return region;
 #elif defined(__aarch64__) || \
+    (defined(__sun) && defined(__x86_64__)) || \
     (defined(__sparc__) && defined(__arch64__) && defined(__linux__))
   /*
    * There might be similar virtual address issue on arm64 which depends on
