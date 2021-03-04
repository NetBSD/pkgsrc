$NetBSD: patch-src_blkdev_blkdev.c,v 1.1 2021/03/04 10:02:44 nia Exp $

https://github.com/dosfstools/dosfstools/commit/8a917ed2afb2dd2a165a93812b6f52b9060eec5f.patch

--- src/blkdev/blkdev.c.orig	2021-01-31 12:49:12.000000000 +0000
+++ src/blkdev/blkdev.c
@@ -7,7 +7,9 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
-#include <sys/sysmacros.h>
+#ifdef HAVE_SYS_SYSMACROS_H
+# include <sys/sysmacros.h>
+#endif
 #include <unistd.h>
 #include <stdint.h>
 #include <stdio.h>
