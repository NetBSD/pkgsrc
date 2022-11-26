$NetBSD: patch-storage_innobase_include_detail_ut_large__page__alloc-linux.h,v 1.1 2022/11/26 12:25:22 nia Exp $

MAP_HUGETLB is unavailable on other operating systems than FreeBSD,
correctly map it as a Linuxism.

--- storage/innobase/include/detail/ut/large_page_alloc-linux.h.orig	2022-09-13 16:15:16.000000000 +0000
+++ storage/innobase/include/detail/ut/large_page_alloc-linux.h
@@ -52,7 +52,7 @@ inline void *large_page_aligned_alloc(si
   // mmap will internally round n_bytes to the multiple of huge-page size if it
   // is not already
   int mmap_flags = MAP_PRIVATE | MAP_ANON;
-#ifndef __FreeBSD__
+#ifdef __linux
   mmap_flags |= MAP_HUGETLB;
 #endif
   void *ptr = mmap(nullptr, n_bytes, PROT_READ | PROT_WRITE, mmap_flags, -1, 0);
