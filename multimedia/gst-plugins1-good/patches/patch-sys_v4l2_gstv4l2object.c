$NetBSD: patch-sys_v4l2_gstv4l2object.c,v 1.6 2025/07/14 16:05:50 wiz Exp $

Sync ifdefs to second location in the same file.

--- sys/v4l2/gstv4l2object.c.orig	2025-07-14 15:52:56.493683618 +0000
+++ sys/v4l2/gstv4l2object.c
@@ -595,10 +595,10 @@ gst_v4l2_object_new (GstElement * elemen
     v4l2object->fd_open = v4l2_fd_open;
     v4l2object->close = v4l2_close;
     v4l2object->dup = v4l2_dup;
-#ifdef __GLIBC__
-    v4l2object->ioctl = v4l2_ioctl;
-#else
+#if defined(__linux__) && !defined(__GLIBC__)
     v4l2object->ioctl = v4l2_ioctl_wrapper;
+#else
+    v4l2object->ioctl = v4l2_ioctl;
 #endif
     v4l2object->read = v4l2_read;
     v4l2object->mmap = v4l2_mmap;
