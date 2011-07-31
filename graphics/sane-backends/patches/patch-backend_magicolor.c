$NetBSD: patch-backend_magicolor.c,v 1.1 2011/07/31 20:05:58 gls Exp $

Fix for pkg/45196. Add sys/socket.h header.

--- backend/magicolor.c.orig	2011-01-30 18:49:46.000000000 +0000
+++ backend/magicolor.c
@@ -50,6 +50,11 @@
 #include <unistd.h>
 #include <errno.h>
 #include <sys/time.h>
+
+#ifdef HAVE_SYS_SOCKET_H
+#include <sys/socket.h>
+#endif
+
 #include <math.h>
 #include <poll.h>
 
