$NetBSD: patch-src_runtime_mach-dep_unix-prof.c,v 1.1 2016/07/03 18:52:32 dholland Exp $

Use own abstractions correctly.

--- src/runtime/mach-dep/unix-prof.c~	2005-01-18 17:58:39.000000000 +0000
+++ src/runtime/mach-dep/unix-prof.c
@@ -34,7 +34,7 @@ void EnableProfSignals ()
  */
 void DisableProfSignals ()
 {
-    SIG_SetHandler (SIGVTALRM, SIG_DFL);
+    SIG_SetDefault (SIGVTALRM);
 
 } /* end of DisableProfSignals */
 
