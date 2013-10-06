$NetBSD: patch-server-client.c,v 1.2 2013/10/06 09:01:41 obache Exp $

* SunOS errno support needs the right include.
* timersub is missing on Solaris10

--- server-client.c.orig	2013-03-26 19:22:31.000000000 +0000
+++ server-client.c
@@ -26,8 +26,24 @@
 #include <time.h>
 #include <unistd.h>
 
+#ifdef __sun
+#include <errno.h>
+#endif
+
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
 void	server_client_check_focus(struct window_pane *);
 void	server_client_check_resize(struct window_pane *);
 void	server_client_check_mouse(struct client *, struct window_pane *);
