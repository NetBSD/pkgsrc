$NetBSD: patch-linux-user_syscall.c,v 1.1 2023/03/27 12:42:07 tnn Exp $

Linux build fix, from upstream.

https://github.com/qemu/qemu/commit/9f0246539ae84a5e21efd1cc4516fc343f08115a.patch
https://github.com/qemu/qemu/commit/6003159ce18faad4e1bc7bf9c85669019cd4950e.patch

--- linux-user/syscall.c.orig	2023-03-27 11:55:56.275345431 +0000
+++ linux-user/syscall.c
@@ -95,50 +95,7 @@
 #include <linux/soundcard.h>
 #include <linux/kd.h>
 #include <linux/mtio.h>
-
-#ifdef HAVE_SYS_MOUNT_FSCONFIG
-/*
- * glibc >= 2.36 linux/mount.h conflicts with sys/mount.h,
- * which in turn prevents use of linux/fs.h. So we have to
- * define the constants ourselves for now.
- */
-#define FS_IOC_GETFLAGS                _IOR('f', 1, long)
-#define FS_IOC_SETFLAGS                _IOW('f', 2, long)
-#define FS_IOC_GETVERSION              _IOR('v', 1, long)
-#define FS_IOC_SETVERSION              _IOW('v', 2, long)
-#define FS_IOC_FIEMAP                  _IOWR('f', 11, struct fiemap)
-#define FS_IOC32_GETFLAGS              _IOR('f', 1, int)
-#define FS_IOC32_SETFLAGS              _IOW('f', 2, int)
-#define FS_IOC32_GETVERSION            _IOR('v', 1, int)
-#define FS_IOC32_SETVERSION            _IOW('v', 2, int)
-
-#define BLKGETSIZE64 _IOR(0x12,114,size_t)
-#define BLKDISCARD _IO(0x12,119)
-#define BLKIOMIN _IO(0x12,120)
-#define BLKIOOPT _IO(0x12,121)
-#define BLKALIGNOFF _IO(0x12,122)
-#define BLKPBSZGET _IO(0x12,123)
-#define BLKDISCARDZEROES _IO(0x12,124)
-#define BLKSECDISCARD _IO(0x12,125)
-#define BLKROTATIONAL _IO(0x12,126)
-#define BLKZEROOUT _IO(0x12,127)
-
-#define FIBMAP     _IO(0x00,1)
-#define FIGETBSZ   _IO(0x00,2)
-
-struct file_clone_range {
-        __s64 src_fd;
-        __u64 src_offset;
-        __u64 src_length;
-        __u64 dest_offset;
-};
-
-#define FICLONE         _IOW(0x94, 9, int)
-#define FICLONERANGE    _IOW(0x94, 13, struct file_clone_range)
-
-#else
 #include <linux/fs.h>
-#endif
 #include <linux/fd.h>
 #if defined(CONFIG_FIEMAP)
 #include <linux/fiemap.h>
