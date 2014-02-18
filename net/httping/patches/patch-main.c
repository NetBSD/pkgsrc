$NetBSD: patch-main.c,v 1.1 2014/02/18 12:13:01 jperkin Exp $

SunOS needs sys/termios.h for TIOCOUTQ.

--- main.c.orig	2013-06-07 13:18:52.000000000 +0000
+++ main.c
@@ -16,6 +16,9 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/termios.h>
+#endif
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <netdb.h>
