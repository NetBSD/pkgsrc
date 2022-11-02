$NetBSD: patch-storage_innobase_include_detail_ut_large__page__alloc-solaris.h,v 1.1 2022/11/02 17:02:10 jperkin Exp $

Avoid -fpermissive errors.

--- storage/innobase/include/detail/ut/large_page_alloc-solaris.h.orig	2022-09-13 16:15:16.000000000 +0000
+++ storage/innobase/include/detail/ut/large_page_alloc-solaris.h
@@ -65,7 +65,7 @@ inline void *large_page_aligned_alloc(si
   struct memcntl_mha m = {};
   m.mha_cmd = MHA_MAPSIZE_VA;
   m.mha_pagesize = large_page_default_size;
-  int ret = memcntl(ptr, n_bytes_rounded, MC_HAT_ADVISE, (caddr_t)&m, 0, 0);
+  int ret = memcntl((caddr_t)ptr, n_bytes_rounded, MC_HAT_ADVISE, (caddr_t)&m, 0, 0);
   if (unlikely(ret == -1)) {
     ib::log_warn(ER_IB_MSG_856)
         << "large_page_aligned_alloc memcntl(ptr, " << n_bytes_rounded
