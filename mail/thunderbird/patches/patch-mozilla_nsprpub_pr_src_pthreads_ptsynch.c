$NetBSD: patch-mozilla_nsprpub_pr_src_pthreads_ptsynch.c,v 1.2 2012/04/28 16:56:59 ryoon Exp $

--- mozilla/nsprpub/pr/src/pthreads/ptsynch.c.orig	2012-04-20 22:40:20.000000000 +0000
+++ mozilla/nsprpub/pr/src/pthreads/ptsynch.c
@@ -842,7 +842,7 @@ PR_IMPLEMENT(PRStatus) PR_DeleteSemaphor
  */
 #if (defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)) \
     || defined(FREEBSD) || defined(OPENBSD) || defined(BSDI) \
-    || defined(DARWIN) || defined(SYMBIAN)
+    || defined(DARWIN) || defined(SYMBIAN) || defined(__DragonFly__)
 /* union semun is defined by including <sys/sem.h> */
 #else
 /* according to X/OPEN we have to define it ourselves */
