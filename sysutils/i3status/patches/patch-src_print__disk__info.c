$NetBSD: patch-src_print__disk__info.c,v 1.3 2022/04/12 14:43:01 nia Exp $

Fix building on BSD. Upstream code was changed and the BSD paths
were not tested.

--- src/print_disk_info.c.orig	2021-11-09 07:27:11.974258400 +0000
+++ src/print_disk_info.c
@@ -127,14 +127,14 @@ void print_disk_info(disk_info_ctx_t *ct
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
     struct statfs buf;
 
-    if (statfs(path, &buf) == -1)
+    if (statfs(ctx->path, &buf) == -1)
         return;
 
     mounted = true;
 #elif defined(__NetBSD__)
     struct statvfs buf;
 
-    if (statvfs(path, &buf) == -1)
+    if (statvfs(ctx->path, &buf) == -1)
         return;
 
     mounted = true;
