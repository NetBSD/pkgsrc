$NetBSD: patch-src_OpenThreads_common_Atomic.cpp,v 1.1 2012/03/07 16:27:35 adam Exp $

Fix C error.

--- src/OpenThreads/common/Atomic.cpp.orig	2012-03-05 21:26:31.000000000 +0000
+++ src/OpenThreads/common/Atomic.cpp
@@ -143,7 +143,7 @@ bool
 AtomicPtr::assign(void* ptrNew, const void* const ptrOld)
 {
 #if defined(_OPENTHREADS_ATOMIC_USE_GCC_BUILTINS)
-    return __sync_bool_compare_and_swap(&_ptr, ptrOld, ptrNew);
+    return __sync_bool_compare_and_swap(&_ptr, (void *)ptrOld, ptrNew);
 #elif defined(_OPENTHREADS_ATOMIC_USE_WIN32_INTERLOCKED)
     return ptrOld == InterlockedCompareExchangePointer((PVOID volatile*)&_ptr, (PVOID)ptrNew, (PVOID)ptrOld);
 #elif defined(_OPENTHREADS_ATOMIC_USE_BSD_ATOMIC)
