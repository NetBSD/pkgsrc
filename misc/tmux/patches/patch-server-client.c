$NetBSD: patch-server-client.c,v 1.4 2016/05/09 12:39:05 fhajny Exp $

* SunOS errno support needs the right include.
* timersub is missing on Solaris10

--- server-client.c.orig	2016-04-04 00:16:53.000000000 +0000
+++ server-client.c
@@ -30,6 +30,18 @@
 
 #include "tmux.h"
 
+#ifndef timersub
+# define timersub(a, b, result)                     \
+    do {                                \
+        (result)->tv_sec = (a)->tv_sec - (b)->tv_sec;       \
+        (result)->tv_usec = (a)->tv_usec - (b)->tv_usec;        \
+        if ((result)->tv_usec < 0) {                            \
+            --(result)->tv_sec;             \
+            (result)->tv_usec += 1000000;           \
+        }                                                       \
+    } while (0)
+#endif
+
 void		server_client_free(int, short, void *);
 void		server_client_check_focus(struct window_pane *);
 void		server_client_check_resize(struct window_pane *);
