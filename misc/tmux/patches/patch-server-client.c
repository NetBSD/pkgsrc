$NetBSD: patch-server-client.c,v 1.5 2017/04/21 11:55:37 fhajny Exp $

* timersub is missing on Solaris10

--- server-client.c.orig	2017-04-20 10:29:06.000000000 +0000
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
 static void	server_client_free(int, short, void *);
 static void	server_client_check_focus(struct window_pane *);
 static void	server_client_check_resize(struct window_pane *);
