$NetBSD: patch-lib_libv4lconvert_libv4lsyscall-priv.h,v 1.2 2022/05/17 11:55:23 jperkin Exp $

Support NetBSD and SunOS.

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
@@ -72,6 +71,16 @@
 #define	MMAP2_PAGE_SHIFT 0
 #endif
 
+#if defined(__sun)
+#include <sys/syscall.h>
+#include <sys/types.h>
+#include <sys/ioccom.h>
+#include <sys/ioctl.h>
+#define	_IOC_NR(cmd) ((cmd) & 0x100)
+#define	_IOC_TYPE(cmd) 'V' /* XXX: hack */
+#define	MMAP2_PAGE_SHIFT 0
+#endif
+
 #undef SYS_OPEN
 #undef SYS_CLOSE
 #undef SYS_IOCTL
@@ -111,6 +120,14 @@ register_t __syscall(quad_t, ...);
 #define SYS_MMAP(addr, len, prot, flags, fd, offset) \
 	__syscall((quad_t)SYS_mmap, (void *)(addr), (size_t)(len), \
 			(int)(prot), (int)(flags), (int)(fd), 0, (off_t)(offset))
+#elif defined(__NetBSD__)
+#define SYS_MMAP(addr, len, prot, flags, fd, offset) \
+	__syscall((quad_t)SYS_mmap, (void *)(addr), (size_t)(len), \
+			(int)(prot), (int)(flags), (int)(fd), 0, (off_t)(offset))
+#elif defined(__sun)
+#define SYS_MMAP(addr, len, prot, flags, fd, offset) \
+	syscall(SYS_mmap, (void *)(addr), (size_t)(len), \
+			(int)(prot), (int)(flags), (int)(fd), 0, (off_t)(offset))
 #else
 #define SYS_MMAP(addr, len, prot, flags, fd, off) \
 	syscall(SYS_mmap2, (void *)(addr), (size_t)(len), \
