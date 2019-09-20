$NetBSD: patch-signal.c,v 1.2 2019/09/20 11:36:28 adam Exp $

Provide a fallback definition of SA_RESTART for QNX 6.5

--- signal.c.orig	2019-07-31 18:28:32.000000000 +0000
+++ signal.c
@@ -90,6 +90,10 @@
 #endif
 #endif
 
+#ifndef SA_RESTART /* Absent in QNX 6.5 */
+#define SA_RESTART 0
+#endif
+
 static int evsig_add(struct event_base *, evutil_socket_t, short, short, void *);
 static int evsig_del(struct event_base *, evutil_socket_t, short, short, void *);
 
