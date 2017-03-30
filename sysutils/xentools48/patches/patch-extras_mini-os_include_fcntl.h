$NetBSD: patch-extras_mini-os_include_fcntl.h,v 1.1 2017/03/30 09:15:10 bouyer Exp $
--- extras/mini-os/include/fcntl.h.orig	2017-03-28 19:38:01.000000000 +0200
+++ extras/mini-os/include/fcntl.h	2017-03-28 19:38:12.000000000 +0200
@@ -93,7 +93,7 @@
 
 #endif
 
-int open(const char *path, int flags, ...) asm("open64");
+int open(const char *path, int flags, ...);
 int fcntl(int fd, int cmd, ...);
 
 #endif
