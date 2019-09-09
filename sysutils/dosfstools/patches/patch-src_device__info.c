$NetBSD: patch-src_device__info.c,v 1.1 2019/09/09 09:26:00 nia Exp $

Support netbsd's spelling for statfs.

--- src/device_info.c.orig	2016-09-15 23:17:27.000000000 +0000
+++ src/device_info.c
@@ -318,7 +318,11 @@ int is_device_mounted(const char *path)
 #endif
 
 #if HAVE_DECL_GETMNTINFO
+#ifdef __NetBSD__
+    struct statvfs *stat;
+#else
     struct statfs *stat;
+#endif
     int count, i;
 
     count = getmntinfo(&stat, 0);
