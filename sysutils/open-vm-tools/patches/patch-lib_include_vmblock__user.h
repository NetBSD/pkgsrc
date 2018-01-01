$NetBSD: patch-lib_include_vmblock__user.h,v 1.2 2018/01/01 06:56:01 ryoon Exp $

--- lib/include/vmblock_user.h.orig	2017-12-15 19:09:51.000000000 +0000
+++ lib/include/vmblock_user.h
@@ -72,6 +72,10 @@
 extern "C" {
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/ioctl.h>
+#endif
+
 static INLINE int
 VMBLOCK_CONTROL_FUSE(int fd,            // IN
                      char op,           // IN
@@ -129,7 +133,7 @@ VMBLOCK_CONTROL(int fd, int op, const ch
    return write(fd, path, op);
 }
 
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 
 static INLINE int
 VMBLOCK_CONTROL(int fd, int cmd, const char *path)
