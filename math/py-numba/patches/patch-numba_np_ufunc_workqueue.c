$NetBSD: patch-numba_np_ufunc_workqueue.c,v 1.1 2020/05/31 20:48:22 joerg Exp $

There is no such portable thing as alloca.h.

--- numba/np/ufunc/workqueue.c.orig	2020-05-31 18:11:59.445121410 +0000
+++ numba/np/ufunc/workqueue.c
@@ -27,7 +27,6 @@ race conditions.
 /* PThread */
 #include <pthread.h>
 #include <unistd.h>
-#include <alloca.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <signal.h>
@@ -40,6 +39,8 @@ race conditions.
 #include "workqueue.h"
 #include "gufunc_scheduler.h"
 
+#define alloca(x) __builtin_alloca(x)
+
 #define _DEBUG 0
 
 /* workqueue is not threadsafe, so we use DSO globals to flag and update various
