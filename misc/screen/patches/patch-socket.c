$NetBSD: patch-socket.c,v 1.6 2025/02/13 19:43:02 rillig Exp $

Include <uio.h> for iovec.

--- socket.c.orig	2025-01-09 02:58:51.269455114 +0000
+++ socket.c
@@ -35,9 +35,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/socket.h>
-#ifdef _OpenBSD_
 #include <sys/uio.h>
-#endif
 #include <sys/un.h>
 #include <utime.h>
 #include <stdint.h>
