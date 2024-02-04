$NetBSD: patch-src_aio_poller__kqueue.inc,v 1.2 2024/02/04 18:44:40 adam Exp $

Fix for newer NetBSD.

--- src/aio/poller_kqueue.inc.orig	2024-02-03 22:45:24.000000000 +0000
+++ src/aio/poller_kqueue.inc
@@ -29,10 +29,15 @@
 
 /*  NetBSD has different definition of udata. */
 #if defined NN_HAVE_NETBSD
+#include <sys/param.h>
+#if __NetBSD_Version__ < 999001400
 #define nn_poller_udata intptr_t
 #else
 #define nn_poller_udata void*
 #endif
+#else
+#define nn_poller_udata void*
+#endif
 
 int nn_poller_init (struct nn_poller *self)
 {
