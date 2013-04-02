$NetBSD: patch-server-client.c,v 1.1 2013/04/02 10:59:50 fhajny Exp $

SunOS errno support needs the right include.

--- server-client.c.orig	2013-04-02 10:54:02.404886167 +0000
+++ server-client.c
@@ -26,6 +26,10 @@
 #include <time.h>
 #include <unistd.h>
 
+#ifdef __sun
+#include <errno.h>
+#endif
+
 #include "tmux.h"
 
 void	server_client_check_focus(struct window_pane *);
