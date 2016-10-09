$NetBSD: patch-vmblockmounter_vmblockmounter.c,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- vmblockmounter/vmblockmounter.c.orig	2016-02-16 20:06:48.000000000 +0000
+++ vmblockmounter/vmblockmounter.c
@@ -223,6 +223,8 @@ main(int argc,          // IN
    /* Go! */
 #if defined(sun)
    mntRes = mount(sourceDir, mountPoint, MS_DATA, VMBLOCK_FS_NAME);
+#elif defined(__NetBSD__)
+   mntRes = mount(sourceDir, mountPoint, MNT_BASIC_FLAGS, VMBLOCK_FS_NAME, sizeof(sourceDir));
 #elif defined(__FreeBSD__)
    {
       struct iovec iov[] = {
