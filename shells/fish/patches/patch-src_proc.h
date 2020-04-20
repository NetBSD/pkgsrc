$NetBSD: patch-src_proc.h,v 1.1 2020/04/20 00:45:07 joerg Exp $

WIFEXITED() is not ICE for legacy reasons, so just skip the assert.

--- src/proc.h.orig	2020-04-19 18:24:08.756343798 +0000
+++ src/proc.h
@@ -70,7 +70,9 @@ class proc_status_t {
     static proc_status_t from_exit_code(int ret) {
         // Some paranoia.
         constexpr int zerocode = w_exitcode(0, 0);
+#ifndef __NetBSD__
         static_assert(WIFEXITED(zerocode), "Synthetic exit status not reported as exited");
+#endif
         return proc_status_t(w_exitcode(ret, 0 /* sig */));
     }
 
