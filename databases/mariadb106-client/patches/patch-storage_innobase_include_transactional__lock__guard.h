$NetBSD: patch-storage_innobase_include_transactional__lock__guard.h,v 1.1.4.1 2022/02/23 09:36:11 bsiegert Exp $

Strange build failures on NetBSD:
error: 'rw_lock' is not an accessible base of 'page_hash_latch'

--- storage/innobase/include/transactional_lock_guard.h.orig	2022-02-10 20:17:09.000000000 +0000
+++ storage/innobase/include/transactional_lock_guard.h
@@ -21,12 +21,6 @@ this program; if not, write to the Free 
 #if defined __powerpc64__ && defined __clang__ && defined __linux__
 #elif defined __powerpc64__&&defined __GNUC__&&defined __linux__&&__GNUC__ > 4
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
