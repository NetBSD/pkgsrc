$NetBSD: patch-nsprpub_pr_src_pthreads_ptsynch.c,v 1.1 2012/01/07 18:47:39 marino Exp $

--- nsprpub/pr/src/pthreads/ptsynch.c.orig	2011-09-02 20:15:44.000000000 +0000
+++ nsprpub/pr/src/pthreads/ptsynch.c
@@ -842,7 +842,7 @@ PR_IMPLEMENT(PRStatus) PR_DeleteSemaphor
  */
 #if (defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)) \
     || defined(FREEBSD) || defined(OPENBSD) || defined(BSDI) \
-    || defined(DARWIN) || defined(SYMBIAN)
+    || defined(DARWIN) || defined(SYMBIAN) || defined(__DragonFly__)
 /* union semun is defined by including <sys/sem.h> */
 #else
 /* according to X/OPEN we have to define it ourselves */
