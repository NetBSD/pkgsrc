$NetBSD: patch-socket.c,v 1.1 2015/02/13 04:44:40 rodent Exp $

--- socket.c.orig	2014-04-26 16:22:43.000000000 +0000
+++ socket.c
@@ -30,6 +30,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+#include <sys/uio.h>
 #if !defined(NAMEDPIPE)
 #include <sys/socket.h>
 #include <sys/un.h>
