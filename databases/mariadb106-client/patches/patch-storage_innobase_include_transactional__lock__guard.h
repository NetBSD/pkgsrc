$NetBSD: patch-storage_innobase_include_transactional__lock__guard.h,v 1.2.2.1 2022/06/05 10:11:03 spz Exp $

Strange build failures on NetBSD:
error: 'rw_lock' is not an accessible base of 'page_hash_latch'

--- storage/innobase/include/transactional_lock_guard.h.orig	2022-05-18 08:34:16.000000000 +0000
+++ storage/innobase/include/transactional_lock_guard.h
@@ -21,12 +21,6 @@ this program; if not, write to the Free 
 #if defined __powerpc64__
 #elif defined __s390__
 #elif defined _MSC_VER && (defined _M_IX86 || defined _M_X64) && !defined(__clang__)
-#elif defined __GNUC__ && (defined __i386__ || defined __x86_64__)
-# if __GNUC__ >= 8
-# elif defined __clang_major__ && __clang_major__ > 6
-# else
-#  define NO_ELISION
-# endif
 #else /* Transactional memory has not been implemented for this ISA */
 # define NO_ELISION
 #endif
