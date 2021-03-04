$NetBSD: patch-src_device__info.c,v 1.2 2021/03/04 10:02:44 nia Exp $

https://github.com/dosfstools/dosfstools/commit/8a917ed2afb2dd2a165a93812b6f52b9060eec5f.patch

Support netbsd's spelling for statfs.

--- src/device_info.c.orig	2021-01-31 12:49:12.000000000 +0000
+++ src/device_info.c
@@ -24,7 +24,10 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
-#include <sys/sysmacros.h>
+
+#ifdef HAVE_SYS_SYSMACROS_H
+# include <sys/sysmacros.h>
+#endif
 
 #ifdef HAVE_LINUX_LOOP_H
 #include <linux/loop.h>
@@ -334,7 +337,11 @@ int is_device_mounted(const char *path)
 #endif
 
 #if HAVE_DECL_GETMNTINFO
+#ifdef __NetBSD__
+    struct statvfs *stat;
+#else
     struct statfs *stat;
+#endif
     int count, i;
 
     count = getmntinfo(&stat, 0);
