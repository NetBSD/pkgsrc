$NetBSD: patch-lib_libv4lconvert_libv4lsyscall-priv.h,v 1.1 2020/09/02 09:54:33 ryoon Exp $

--- lib/libv4lconvert/libv4lsyscall-priv.h.orig	2017-01-22 17:33:34.000000000 +0000
+++ lib/libv4lconvert/libv4lsyscall-priv.h
@@ -59,11 +59,10 @@
 #define	_IOC_NR(cmd) ((cmd) & 0xFF)
 #define	_IOC_TYPE(cmd) IOCGROUP(cmd)
 #define	_IOC_SIZE(cmd) IOCPARM_LEN(cmd)
-#define	MAP_ANONYMOUS MAP_ANON
 #define	MMAP2_PAGE_SHIFT 0
 #endif
 
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/syscall.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
@@ -111,6 +110,10 @@ register_t __syscall(quad_t, ...);
 #define SYS_MMAP(addr, len, prot, flags, fd, offset) \
 	__syscall((quad_t)SYS_mmap, (void *)(addr), (size_t)(len), \
 			(int)(prot), (int)(flags), (int)(fd), 0, (off_t)(offset))
+#elif defined(__NetBSD__)
+#define SYS_MMAP(addr, len, prot, flags, fd, offset) \
+	__syscall((quad_t)SYS_mmap, (void *)(addr), (size_t)(len), \
+			(int)(prot), (int)(flags), (int)(fd), 0, (off_t)(offset))
 #else
 #define SYS_MMAP(addr, len, prot, flags, fd, off) \
 	syscall(SYS_mmap2, (void *)(addr), (size_t)(len), \
