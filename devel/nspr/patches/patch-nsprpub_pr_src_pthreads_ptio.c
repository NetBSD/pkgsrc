$NetBSD: patch-nsprpub_pr_src_pthreads_ptio.c,v 1.4 2019/12/03 14:28:26 ryoon Exp $

--- nspr/pr/src/pthreads/ptio.c.orig	2019-10-15 14:21:38.000000000 +0000
+++ nspr/pr/src/pthreads/ptio.c
@@ -183,7 +183,7 @@ static PRBool _pr_ipv6_v6only_on_by_defa
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
     || defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
     || defined(BSDI) || defined(NTO) || defined(DARWIN) \
-    || defined(UNIXWARE) || defined(RISCOS)
+    || defined(UNIXWARE) || defined(RISCOS) || defined(__DragonFly__)
 #define _PRSelectFdSetArg_t fd_set *
 #else
 #error "Cannot determine architecture"
@@ -3477,7 +3477,8 @@ static PRIOMethods _pr_socketpollfd_meth
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
     || defined(AIX) || defined(FREEBSD) || defined(NETBSD) \
     || defined(OPENBSD) || defined(BSDI) || defined(NTO) \
-    || defined(DARWIN) || defined(UNIXWARE) || defined(RISCOS)
+    || defined(DARWIN) || defined(UNIXWARE) || defined(RISCOS) \
+    || defined(__DragonFly__)
 #define _PR_FCNTL_FLAGS O_NONBLOCK
 #else
 #error "Can't determine architecture"
