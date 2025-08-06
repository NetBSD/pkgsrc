$NetBSD: patch-src_hotspot_os__cpu_bsd__aarch64_os__bsd__aarch64.cpp,v 1.5 2025/08/06 08:47:16 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp.orig	2025-08-05 06:55:35.035540383 +0000
+++ src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp
@@ -765,6 +765,11 @@ bool PosixSignals::pd_hotspot_signal_han
     assert(sig == info->si_signo, "bad siginfo");
   }
 */
+
+  // Enable WXWrite: this function is called by the signal handler at arbitrary
+  // point of execution.
+  ThreadWXEnable wx(WXWrite, thread);
+
   // decide if this trap can be handled by a stub
   address stub = NULL;
 
