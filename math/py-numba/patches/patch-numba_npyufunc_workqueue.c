$NetBSD: patch-numba_npyufunc_workqueue.c,v 1.1 2018/12/27 15:06:19 joerg Exp $

--- numba/npyufunc/workqueue.c.orig	2018-12-25 21:11:57.183814489 +0000
+++ numba/npyufunc/workqueue.c
@@ -19,7 +19,10 @@ race condition.
 /* PThread */
 #include <pthread.h>
 #include <unistd.h>
+#include <stdlib.h>
+#ifdef __sun
 #include <alloca.h>
+#endif
 #define NUMBA_PTHREAD
 #endif
 
