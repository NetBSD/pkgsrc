$NetBSD: patch-signal.c,v 1.1 2017/09/23 03:24:55 maya Exp $

Provide a fallback definition of SA_RESTART for QNX 6.5

--- signal.c.orig	2016-10-04 19:55:31.000000000 +0000
+++ signal.c
@@ -88,6 +88,10 @@
 #define __cdecl
 #endif
 
+#ifndef SA_RESTART /* Absent in QNX 6.5 */
+#define SA_RESTART 0
+#endif
+
 static int evsig_add(struct event_base *, evutil_socket_t, short, short, void *);
 static int evsig_del(struct event_base *, evutil_socket_t, short, short, void *);
 
