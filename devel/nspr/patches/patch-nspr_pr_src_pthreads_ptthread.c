$NetBSD: patch-nspr_pr_src_pthreads_ptthread.c,v 1.2 2021/07/01 07:23:00 wiz Exp $

pthread_t may be 64-bit, avoid casting it.
https://bugzilla.mozilla.org/show_bug.cgi?id=1718835

--- nspr/pr/src/pthreads/ptthread.c.orig	2018-01-18 12:37:14.000000000 +0000
+++ nspr/pr/src/pthreads/ptthread.c
@@ -1122,7 +1122,7 @@ PR_IMPLEMENT(void) PR_ProcessExit(PRIntn
     _exit(status);
 }
 
-PR_IMPLEMENT(PRUint32) PR_GetThreadID(PRThread *thred)
+PR_IMPLEMENT(pthread_t) PR_GetThreadID(PRThread *thred)
 {
     return (PRUint32)thred->id;  /* and I don't know what they will do with it */
 }
