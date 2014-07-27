$NetBSD: patch-mozilla_js_src_gc_Memory.cpp,v 1.1 2014/07/27 20:04:59 ryoon Exp $

--- mozilla/js/src/gc/Memory.cpp.orig	2014-07-18 00:05:25.000000000 +0000
+++ mozilla/js/src/gc/Memory.cpp
@@ -212,7 +212,7 @@ gc::InitMemorySubsystem(JSRuntime *rt)
 static inline void *
 MapMemory(size_t length, int prot, int flags, int fd, off_t offset)
 {
-#if defined(__ia64__)
+#if defined(__ia64__) || (defined(__sparc64__) && defined(__NetBSD__))
     /*
      * The JS engine assumes that all allocated pointers have their high 17 bits clear,
      * which ia64's mmap doesn't support directly. However, we can emulate it by passing
