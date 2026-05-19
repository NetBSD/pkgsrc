$NetBSD: patch-nspr_pr_src_pthreads_ptio.c,v 1.1 2026/05/19 08:48:15 jperkin Exp $

Fix for modern C.

--- nspr/pr/src/pthreads/ptio.c.orig	2026-05-19 08:43:03.954529380 +0000
+++ nspr/pr/src/pthreads/ptio.c
@@ -72,7 +72,7 @@ typedef struct sendfilevec {
 /*
  * extern ssize_t sendfilev(int, const struct sendfilevec *, int, size_t *);
  */
-static ssize_t (*pt_solaris_sendfilev_fptr)() = NULL;
+static ssize_t (*pt_solaris_sendfilev_fptr)(int, const struct sendfilevec *, int, size_t *) = NULL;
 
 #      define SOLARIS_SENDFILEV(a, b, c, d) \
         (*pt_solaris_sendfilev_fptr)((a), (b), (c), (d))
@@ -2368,7 +2368,7 @@ static void pt_solaris_sendfilev_init_ro
     PR_LOG(_pr_io_lm, PR_LOG_DEBUG, ("dlopen(0) returns %p", handle));
     close_it = PR_TRUE;
   }
-  pt_solaris_sendfilev_fptr = (ssize_t(*)())dlsym(handle, "sendfilev");
+  pt_solaris_sendfilev_fptr = (ssize_t(*)(int, const struct sendfilevec *, int, size_t *))dlsym(handle, "sendfilev");
   PR_LOG(_pr_io_lm, PR_LOG_DEBUG,
          ("dlsym(sendfilev) returns %p", pt_solaris_sendfilev_fptr));
 
