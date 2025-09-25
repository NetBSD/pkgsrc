$NetBSD: patch-figlet.c,v 1.1 2025/09/25 05:33:30 mrg Exp $

NetBSD and others only define __unix__ these days.


--- figlet.c.orig	2012-06-01 05:51:09.000000000 -0700
+++ figlet.c	2025-09-24 22:27:16.521133495 -0700
@@ -66,7 +66,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>     /* Needed for get_columns */
 
-#ifdef unix
+#if defined(unix) || defined(__unix__)
 #include <unistd.h>
 #include <sys/ioctl.h> /* Needed for get_columns */
 #endif
