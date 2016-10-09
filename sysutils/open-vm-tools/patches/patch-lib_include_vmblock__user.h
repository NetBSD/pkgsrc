$NetBSD: patch-lib_include_vmblock__user.h,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- lib/include/vmblock_user.h.orig	2016-02-16 20:06:46.000000000 +0000
+++ lib/include/vmblock_user.h
@@ -68,6 +68,10 @@
 #include "vm_basic_types.h"
 #include "vmblock.h"
 
+#if defined(__NetBSD__)
+#include <sys/ioctl.h>
+#endif
+
 static INLINE int
 VMBLOCK_CONTROL_FUSE(int fd,            // IN
                      char op,           // IN
@@ -125,7 +129,7 @@ VMBLOCK_CONTROL(int fd, int op, const ch
    return write(fd, path, op);
 }
 
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 
 static INLINE int
 VMBLOCK_CONTROL(int fd, int cmd, const char *path)
