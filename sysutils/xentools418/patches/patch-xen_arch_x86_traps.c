$NetBSD: patch-xen_arch_x86_traps.c,v 1.1 2025/05/29 12:16:56 bouyer Exp $

Pull in upstream commit d965e2ee07c56c341d8896852550914d87ea5374
 x86/pv: Fix breakpoint reporting

 x86_merge_dr6() is not a no-op when 0 is passed in; it will discard the
 previously latched breakpoint bits.

 The combination of do_debug()'s manual call to x86_merge_dr6() for external
 debuggers, and pv_inject_DB() calling pv_inject_event(), results in two
 x86_merge_dr6() calls.

 Feed the same pending_dbg in the second time.  This makes pv_inject_event()'s
 update of dr6 effectively a no-op, retaining the correct breakpoint bits.

--- xen/arch/x86/traps.c.orig	2025-05-26 22:44:28.709656168 +0200
+++ xen/arch/x86/traps.c	2025-05-26 22:45:24.128811203 +0200
@@ -2064,7 +2064,7 @@
         return;
     }
 
-    pv_inject_DB(0 /* N/A, already merged */);
+    pv_inject_DB(dr6 ^ X86_DR6_DEFAULT);
 }
 
 /* SAF-1-safe */
