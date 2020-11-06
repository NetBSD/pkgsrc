$NetBSD: patch-src_lj__ccallback.c,v 1.1 2020/11/06 12:15:53 nia Exp $

Make this PaX-MPROTECT safe on NetBSD.

--- src/lj_ccallback.c.orig	2017-05-01 18:11:00.000000000 +0000
+++ src/lj_ccallback.c
@@ -228,8 +228,12 @@ static void callback_mcode_new(CTState *
   if (!p)
     lj_err_caller(cts->L, LJ_ERR_FFI_CBACKOV);
 #elif LJ_TARGET_POSIX
-  p = mmap(NULL, sz, (PROT_READ|PROT_WRITE), MAP_PRIVATE|MAP_ANONYMOUS,
-	   -1, 0);
+#ifdef PROT_MPROTECT
+  p = mmap(NULL, sz, (PROT_READ|PROT_WRITE) | PROT_MPROTECT(PROT_EXEC),
+#else
+  p = mmap(NULL, sz, (PROT_READ|PROT_WRITE),
+#endif
+           MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
   if (p == MAP_FAILED)
     lj_err_caller(cts->L, LJ_ERR_FFI_CBACKOV);
 #else
