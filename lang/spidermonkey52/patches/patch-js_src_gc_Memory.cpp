$NetBSD: patch-js_src_gc_Memory.cpp,v 1.1 2018/05/11 19:18:35 jperkin Exp $

Support SunOS/x86_64.

--- js/src/gc/Memory.cpp.orig	2018-04-28 01:04:03.000000000 +0000
+++ js/src/gc/Memory.cpp
@@ -501,7 +501,7 @@ static inline void*
 MapMemoryAt(void* desired, size_t length, int prot = PROT_READ | PROT_WRITE,
             int flags = MAP_PRIVATE | MAP_ANON, int fd = -1, off_t offset = 0)
 {
-#if defined(__ia64__) || (defined(__sparc64__) && defined(__NetBSD__)) || defined(__aarch64__)
+#if defined(__ia64__) || (defined(__sparc64__) && defined(__NetBSD__)) || defined(__aarch64__) || (defined(__sun) && defined(__x86_64__))
     MOZ_ASSERT((0xffff800000000000ULL & (uintptr_t(desired) + length - 1)) == 0);
 #endif
     void* region = mmap(desired, length, prot, flags, fd, offset);
@@ -551,7 +551,7 @@ MapMemory(size_t length, int prot = PROT
         return nullptr;
     }
     return region;
-#elif defined(__aarch64__)
+#elif defined(__aarch64__) || (defined(__sun) && defined(__x86_64__))
    /*
     * There might be similar virtual address issue on arm64 which depends on
     * hardware and kernel configurations. But the work around is slightly
@@ -763,7 +763,11 @@ MarkPagesUnused(void* p, size_t size)
         return false;
 
     MOZ_ASSERT(OffsetFromAligned(p, pageSize) == 0);
+#ifdef __sun
+    int result = posix_madvise(p, size, MADV_DONTNEED);
+#else
     int result = madvise(p, size, MADV_DONTNEED);
+#endif
     return result != -1;
 }
 
