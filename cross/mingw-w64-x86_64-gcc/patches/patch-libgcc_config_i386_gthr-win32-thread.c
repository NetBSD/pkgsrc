$NetBSD: patch-libgcc_config_i386_gthr-win32-thread.c,v 1.1 2026/11/09 23:05:14 js Exp $

Don't use GetThreadId(), which does not exist before Vista.

Since GCC already uses DuplicateHandle() and uses TLS to store the result, we
can just compare pointers.

--- libgcc/config/i386/gthr-win32-thread.c.orig	2026-11-09 22:27:29.993414402 +0000
+++ libgcc/config/i386/gthr-win32-thread.c
@@ -116,7 +116,7 @@ __gthr_win32_join (__gthread_t thr, void
 {
   int status = 0;
 
-  if (GetThreadId ((HANDLE) thr) == GetCurrentThreadId ())
+  if (thr == __gthr_win32_self ())
     return 1;
 
   if (WaitForSingleObject ((HANDLE) thr, INFINITE) == WAIT_OBJECT_0)
