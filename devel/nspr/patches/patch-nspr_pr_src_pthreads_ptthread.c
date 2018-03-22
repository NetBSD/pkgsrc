$NetBSD: patch-nspr_pr_src_pthreads_ptthread.c,v 1.1.2.2 2018/03/22 06:56:21 spz Exp $

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
