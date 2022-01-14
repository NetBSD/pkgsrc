$NetBSD: patch-numba_np_ufunc_workqueue.c,v 1.2 2022/01/14 19:52:24 adam Exp $

There is no such portable thing as alloca.h.

--- numba/np/ufunc/workqueue.c.orig	2022-01-14 01:24:55.000000000 +0000
+++ numba/np/ufunc/workqueue.c
@@ -28,7 +28,7 @@ race conditions.
 #include <pthread.h>
 #include <unistd.h>
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <stdlib.h>
 #else
 #include <alloca.h>
