$NetBSD: patch-libgcc_config_i386_gthr-win32.h,v 1.1 2026/11/09 23:05:14 js Exp $

Don't use GetThreadId(), which does not exist before Vista.

Since GCC already uses DuplicateHandle() and uses TLS to store the result, we
can just compare pointers.

--- libgcc/config/i386/gthr-win32.h.orig	2026-11-09 22:29:21.617350049 +0000
+++ libgcc/config/i386/gthr-win32.h
@@ -625,7 +625,7 @@ __gthread_detach (__gthread_t __thr)
 __GTHREAD_WIN32_INLINE int
 __gthread_equal (__gthread_t __t1, __gthread_t __t2)
 {
-  return GetThreadId ((HANDLE) __t1) == GetThreadId ((HANDLE) __t2);
+  return __t1 == __t2;
 }
 
 __GTHREAD_WIN32_INLINE int
