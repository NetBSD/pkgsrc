$NetBSD: patch-src_print__disk__info.c,v 1.1 2016/06/14 06:39:37 kamil Exp $

* mntent.h and setmntent stuff is linux only
* NetBSD has statvfs structure, not statfs

--- src/print_disk_info.c.orig	2016-01-01 18:51:19.000000000 +0000
+++ src/print_disk_info.c
@@ -7,11 +7,11 @@
 #include <sys/stat.h>
 #include <sys/statvfs.h>
 #include <sys/types.h>
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || (__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
+#if defined(__linux__)
+#include <mntent.h>
+#else
 #include <sys/param.h>
 #include <sys/mount.h>
-#else
-#include <mntent.h>
 #endif
 #include <yajl/yajl_gen.h>
 #include <yajl/yajl_version.h>
@@ -116,12 +116,7 @@ void print_disk_info(yajl_gen json_gen, 
 
     INSTANCE(path);
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
-    struct statfs buf;
-
-    if (statfs(path, &buf) == -1)
-        return;
-#else
+#if defined(__linux__)
     struct statvfs buf;
 
     if (statvfs(path, &buf) == -1) {
@@ -145,6 +140,16 @@ void print_disk_info(yajl_gen json_gen, 
             format = format_not_mounted;
         }
     }
+#elif defined(__NetBSD__)
+    struct statvfs buf;
+
+    if (statvfs(path, &buf) == -1)
+        format = format_not_mounted;
+#else
+    struct statfs buf;
+
+    if (statfs(path, &buf) == -1)
+        return;
 #endif
 
     if (low_threshold > 0 && below_threshold(buf, prefix_type, threshold_type, low_threshold)) {
