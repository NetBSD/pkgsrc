$NetBSD: patch-rts_StgCRun.c,v 1.1 2020/02/17 17:26:53 jperkin Exp $

https://gitlab.haskell.org/ghc/ghc/merge_requests/2607/diffs

--- rts/StgCRun.c.orig	2019-08-25 04:26:28.000000000 +0000
+++ rts/StgCRun.c
@@ -405,7 +405,7 @@ StgRunIsImplementedInAssembler(void)
         "movq %%xmm15,136(%%rax)\n\t"
 #endif
 
-#if !defined(darwin_HOST_OS)
+#if !defined(darwin_HOST_OS) && !defined(solaris2_HOST_OS)
         /*
          * Let the unwinder know where we saved the registers
          * See Note [Unwinding foreign exports on x86-64].
@@ -519,7 +519,7 @@ StgRunIsImplementedInAssembler(void)
           "i"(RESERVED_C_STACK_BYTES + STG_RUN_STACK_FRAME_SIZE
               /* rip relative to cfa */)
 
-#if !defined(darwin_HOST_OS)
+#if !defined(darwin_HOST_OS) && !defined(solaris2_HOST_OS)
           , "i"((RSP_DELTA & 127) | (128 * ((RSP_DELTA >> 7) > 0)))
             /* signed LEB128-encoded delta from rsp - byte 1 */
 #if (RSP_DELTA >> 7) > 0
