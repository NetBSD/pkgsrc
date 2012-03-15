$NetBSD: patch-nsprpub_pr_src_pthreads_ptio.c,v 1.1.1.1 2012/03/15 08:58:28 ryoon Exp $

--- nsprpub/pr/src/pthreads/ptio.c.orig	2012-03-09 22:20:31.000000000 +0000
+++ nsprpub/pr/src/pthreads/ptio.c
@@ -212,7 +212,8 @@ static PRBool _pr_ipv6_v6only_on_by_defa
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
     || defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
     || defined(BSDI) || defined(NTO) || defined(DARWIN) \
-    || defined(UNIXWARE) || defined(RISCOS) || defined(SYMBIAN)
+    || defined(UNIXWARE) || defined(RISCOS) || defined(SYMBIAN) \
+    || defined(__DragonFly__)
 #define _PRSelectFdSetArg_t fd_set *
 #else
 #error "Cannot determine architecture"
@@ -3286,7 +3287,7 @@ static PRIOMethods _pr_socketpollfd_meth
     || defined(AIX) || defined(FREEBSD) || defined(NETBSD) \
     || defined(OPENBSD) || defined(BSDI) || defined(NTO) \
     || defined(DARWIN) || defined(UNIXWARE) || defined(RISCOS) \
-    || defined(SYMBIAN)
+    || defined(SYMBIAN) || defined(__DragonFly__)
 #define _PR_FCNTL_FLAGS O_NONBLOCK
 #else
 #error "Can't determine architecture"
