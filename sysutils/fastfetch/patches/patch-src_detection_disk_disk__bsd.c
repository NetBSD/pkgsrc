$NetBSD: patch-src_detection_disk_disk__bsd.c,v 1.1 2025/01/17 16:28:09 vins Exp $

Silence sign conversion warning.

--- src/detection/disk/disk_bsd.c.orig	2025-01-17 16:06:46.666195362 +0000
+++ src/detection/disk/disk_bsd.c
@@ -131,7 +131,7 @@ const char* ffDetectDisksImpl(FFDiskOpti
         return "getfsstat(NULL, 0, MNT_WAIT) failed";
 
     FF_AUTO_FREE struct statfs* buf = malloc(sizeof(*buf) * (unsigned) size);
-    if(getfsstat(buf, (int) (sizeof(*buf) * (unsigned) size), MNT_NOWAIT) <= 0)
+    if(getfsstat(buf, (uint) (sizeof(*buf) * (unsigned) size), MNT_NOWAIT) <= 0)
         return "getfsstat(buf, size, MNT_NOWAIT) failed";
 
     for(struct statfs* fs = buf; fs < buf + size; ++fs)
