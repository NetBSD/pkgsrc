$NetBSD: patch-nsprpub_pr_src_pthreads_ptsynch.c,v 1.2 2012/08/28 13:29:17 ryoon Exp $

--- nsprpub/pr/src/pthreads/ptsynch.c.orig	2012-03-06 13:14:21.000000000 +0000
+++ nsprpub/pr/src/pthreads/ptsynch.c
@@ -810,7 +810,7 @@ PR_IMPLEMENT(PRStatus) PR_DeleteSemaphor
  */
 #if (defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)) \
     || defined(FREEBSD) || defined(OPENBSD) || defined(BSDI) \
-    || defined(DARWIN) || defined(SYMBIAN)
+    || defined(DARWIN) || defined(SYMBIAN) || defined(__DragonFly__)
 /* union semun is defined by including <sys/sem.h> */
 #else
 /* according to X/OPEN we have to define it ourselves */
