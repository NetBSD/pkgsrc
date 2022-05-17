$NetBSD: patch-lib_libv4l1_libv4l1.c,v 1.2 2022/05/17 11:55:23 jperkin Exp $

Support NetBSD and SunOS.

--- lib/libv4l1/libv4l1.c.orig	2020-05-02 12:16:20.000000000 +0000
+++ lib/libv4l1/libv4l1.c
@@ -58,7 +58,7 @@
 #include <sys/types.h>
 #include <sys/mman.h>
 #include "../libv4lconvert/libv4lsyscall-priv.h"
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
@@ -472,7 +472,11 @@ int v4l1_dup(int fd)
 	int index = v4l1_get_index(fd);
 
 	if (index == -1)
+#ifdef __sun
+		return syscall(SYS_fcntl, fd, F_DUPFD, 0);
+#else
 		return syscall(SYS_dup, fd);
+#endif
 
 	devices[index].open_count++;
 
