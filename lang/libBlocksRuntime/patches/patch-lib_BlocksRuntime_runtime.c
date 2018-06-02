$NetBSD: patch-lib_BlocksRuntime_runtime.c,v 1.1 2018/06/02 19:11:01 joerg Exp $

--- lib/BlocksRuntime/runtime.c.orig	2018-05-07 16:23:23.420191743 +0000
+++ lib/BlocksRuntime/runtime.c
@@ -69,9 +69,9 @@ static __inline bool OSAtomicCompareAndS
 
 #elif defined(HAVE_SYNC_BOOL_COMPARE_AND_SWAP_INT) && defined(HAVE_SYNC_BOOL_COMPARE_AND_SWAP_LONG)
 
-static __inline bool OSAtomicCompareAndSwapLong(long oldl, long newl, long volatile *dst) {
-  return __sync_bool_compare_and_swap(dst, oldl, newl);
-}
+/*static __inline bool OSAtomicCompareAndSwapLong(long oldl, long newl, long volatile *dst) {
+ *  return __sync_bool_compare_and_swap(dst, oldl, newl);
+ }*/
 
 static __inline bool OSAtomicCompareAndSwapInt(int oldi, int newi, int volatile *dst) {
   return __sync_bool_compare_and_swap(dst, oldi, newi);
