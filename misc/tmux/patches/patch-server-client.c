$NetBSD: patch-server-client.c,v 1.3 2015/12/31 07:07:16 ryoon Exp $

* SunOS errno support needs the right include.
* timersub is missing on Solaris10

--- server-client.c.orig	2015-10-18 17:10:43.000000000 +0000
+++ server-client.c
@@ -29,6 +29,18 @@
 
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
 void	server_client_key_table(struct client *, const char *);
 void	server_client_free(int, short, void *);
 void	server_client_check_focus(struct window_pane *);
