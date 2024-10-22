$NetBSD: patch-nspr_pr_src_pthreads_ptthread.c,v 1.4 2024/10/22 12:52:02 ryoon Exp $

pthread_t may be 64-bit, avoid casting it.
https://bugzilla.mozilla.org/show_bug.cgi?id=1718835

--- nspr/pr/src/pthreads/ptthread.c.orig	2024-10-21 11:31:57.000000000 +0000
+++ nspr/pr/src/pthreads/ptthread.c
@@ -1088,8 +1088,8 @@ PR_IMPLEMENT(PRStatus) PR_Cleanup(void) 
 
 PR_IMPLEMENT(void) PR_ProcessExit(PRIntn status) { _exit(status); }
 
-PR_IMPLEMENT(PRUint32) PR_GetThreadID(PRThread* thred) {
-  return (PRUint32)thred->id; /* and I don't know what they will do with it */
+PR_IMPLEMENT(pthread_t) PR_GetThreadID(PRThread* thred) {
+  return (pthread_t)thred->id; /* and I don't know what they will do with it */
 }
 
 /*
