$NetBSD: patch-nspr_pr_src_pthreads_ptthread.c,v 1.6 2026/11/18 21:52:11 wiz Exp $

pthread_t may be 64-bit, avoid casting it.
https://bugzilla.mozilla.org/show_bug.cgi?id=1718835

--- nspr/pr/src/pthreads/ptthread.c.orig	2026-11-18 18:00:24.000000000 +0000
+++ nspr/pr/src/pthreads/ptthread.c
@@ -1106,10 +1106,10 @@ PR_ProcessExit(PRIntn status) { _exit(status); }
 PR_IMPLEMENT(void)
 PR_ProcessExit(PRIntn status) { _exit(status); }
 
-PR_IMPLEMENT(PRUint32)
+PR_IMPLEMENT(pthread_t)
 PR_GetThreadID(PRThread* thred)
 {
-    return (PRUint32)thred->id; /* and I don't know what they will do with it */
+    return thred->id; /* and I don't know what they will do with it */
 }
 
 /*
