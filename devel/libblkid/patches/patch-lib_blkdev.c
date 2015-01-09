$NetBSD: patch-lib_blkdev.c,v 1.1 2015/01/09 14:27:46 joerg Exp $

--- lib/blkdev.c.orig	2010-05-19 21:36:23.000000000 +0000
+++ lib/blkdev.c
@@ -104,7 +104,7 @@ blkdev_get_size(int fd, unsigned long lo
 #ifdef DIOCGMEDIASIZE
 	/* FreeBSD */
 	if (ioctl(fd, DIOCGMEDIASIZE, bytes) >= 0)
-		return 0
+		return 0;
 #endif
 
 #ifdef FDGETPRM
