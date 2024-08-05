$NetBSD: patch-storage_innobase_include_detail_ut_large__page__alloc-linux.h,v 1.1 2024/08/05 01:24:00 jnemeth Exp $

--- storage/innobase/include/detail/ut/large_page_alloc-linux.h.orig	2022-03-23 13:49:36.000000000 +0000
+++ storage/innobase/include/detail/ut/large_page_alloc-linux.h
@@ -52,7 +52,7 @@ inline void *large_page_aligned_alloc(si
   // mmap will internally round n_bytes to the multiple of huge-page size if it
   // is not already
   int mmap_flags = MAP_PRIVATE | MAP_ANON;
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
   mmap_flags |= MAP_HUGETLB;
 #endif
   void *ptr = mmap(nullptr, n_bytes, PROT_READ | PROT_WRITE, mmap_flags, -1, 0);
