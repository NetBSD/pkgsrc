$NetBSD: patch-libraries_process_cbits_posix_fork__exec.c,v 1.3 2023/10/09 02:49:52 pho Exp $

Ensure _POSIX_PTHREAD_SEMANTICS is defined on SunOS.

Pull request:
https://github.com/haskell/process/pull/274

--- libraries/process/cbits/posix/fork_exec.c.orig	2023-08-21 03:50:41.000000000 +0000
+++ libraries/process/cbits/posix/fork_exec.c
@@ -1,6 +1,10 @@
 /* ensure that execvpe is provided if possible */
 #define _GNU_SOURCE 1
 
+#ifdef __sun
+#define _POSIX_PTHREAD_SEMANTICS
+#endif
+
 #include "common.h"
 
 #if defined(HAVE_FORK)
