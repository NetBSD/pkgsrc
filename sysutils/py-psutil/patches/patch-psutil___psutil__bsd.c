$NetBSD: patch-psutil___psutil__bsd.c,v 1.5 2016/02/10 13:20:28 wiz Exp $

1. chunk: Workaround for DTYPE_VNODE not being available in public
headers, even with _KERNEL set, on NetBSD-6.

2. chunk: MNT_DISCARD not available on NetBSD-6.

https://github.com/giampaolo/psutil/pull/764

--- psutil/_psutil_bsd.c.orig	2016-01-20 16:26:28.000000000 +0000
+++ psutil/_psutil_bsd.c
@@ -100,6 +100,9 @@
 #define _KERNEL
     #include <uvm/uvm_extern.h>
 #undef _KERNEL
+    #ifndef DTYPE_VNODE
+    #define DTYPE_VNODE 1
+    #endif
 #endif
 
 
@@ -703,8 +706,10 @@ psutil_disk_partitions(PyObject *self, P
             strlcat(opts, ",relatime", sizeof(opts));
         if (flags & MNT_IGNORE)
             strlcat(opts, ",ignore", sizeof(opts));
+#if defined(MNT_DISCARD)
         if (flags & MNT_DISCARD)
             strlcat(opts, ",discard", sizeof(opts));
+#endif
         if (flags & MNT_EXTATTR)
             strlcat(opts, ",extattr", sizeof(opts));
         if (flags & MNT_LOG)
