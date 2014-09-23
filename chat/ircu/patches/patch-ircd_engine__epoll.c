$NetBSD: patch-ircd_engine__epoll.c,v 1.1 2014/09/23 22:13:50 jperkin Exp $

Fix SunOS epoll build.

--- ircd/engine_epoll.c.orig	2005-08-25 01:26:46.000000000 +0000
+++ ircd/engine_epoll.c
@@ -39,7 +39,9 @@
 #include <sys/epoll.h>
 #include <sys/socket.h>
 #include <time.h>
+#ifndef __sun
 #include <linux/unistd.h>
+#endif
 
 /* The GNU C library may have a valid header but stub implementations
  * of the epoll system calls.  If so, provide our own. */
