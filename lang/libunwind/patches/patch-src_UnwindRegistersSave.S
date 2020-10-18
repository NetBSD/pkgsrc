$NetBSD: patch-src_UnwindRegistersSave.S,v 1.1 2020/10/18 17:06:35 he Exp $

Gcc doesn't define __ppc__, but defines __powerpc__ on NetBSD/powerpc.

--- src/UnwindRegistersSave.S.orig	2020-07-07 16:21:37.000000000 +0000
+++ src/UnwindRegistersSave.S
@@ -554,7 +554,7 @@ DEFINE_LIBUNWIND_FUNCTION(__unw_getconte
   blr
 
 
-#elif defined(__ppc__)
+#elif defined(__ppc__) || defined(__powerpc__)
 
 //
 // extern int unw_getcontext(unw_context_t* thread_state)
