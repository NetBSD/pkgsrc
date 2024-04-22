$NetBSD: patch-src_runtime_mach-dep_unix-fault.c,v 1.1 2024/04/22 18:35:06 he Exp $

Ignore absence of SIG_OVERFLOW.

--- src/runtime/mach-dep/unix-fault.c.orig	2022-07-28 04:55:45.000000000 +0000
+++ src/runtime/mach-dep/unix-fault.c
@@ -47,8 +47,6 @@ void InitFaultHandlers (ml_state_t *msp)
   /** Set up the Overflow fault(s) **/
 #ifdef SIG_OVERFLOW
     SIG_SetHandler (SIG_OVERFLOW, FaultHandler);
-#else
-# error now signal for Overflow specified
 #endif
 #ifdef SIG_OVERFLOW2
     SIG_SetHandler (SIG_OVERFLOW2, FaultHandler);
