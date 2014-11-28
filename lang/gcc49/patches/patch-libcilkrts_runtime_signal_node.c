$NetBSD: patch-libcilkrts_runtime_signal_node.c,v 1.1 2014/11/28 11:47:01 bsiegert Exp $

Work around broken <semaphore.h> in glibc < 2.5.

Corresponding Debian bug report:
https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=402318

--- libcilkrts/runtime/signal_node.c.orig       2014-10-20 00:37:57.000000000 +0200
+++ libcilkrts/runtime/signal_node.c    2014-10-20 00:38:36.000000000 +0200
@@ -51,6 +51,7 @@
     typedef HANDLE cilk_semaphore_t;
 #else // Linux/MIC
 #   include <errno.h>
+#   include <pthread.h>
 #   include <semaphore.h>
 #   include <stdio.h>
     typedef sem_t cilk_semaphore_t;
