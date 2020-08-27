$NetBSD: patch-tools_debugger_gdbsx_xg_xg_main.c,v 1.2 2020/08/27 08:22:33 bouyer Exp $

--- tools/debugger/gdbsx/xg/xg_main.c.orig	2020-05-14 14:19:32.000000000 +0200
+++ tools/debugger/gdbsx/xg/xg_main.c	2020-08-26 23:12:04.349806717 +0200
@@ -49,7 +49,11 @@
 #include "xg_public.h"
 #include <xen/version.h>
 #include <xen/domctl.h>
+#ifdef __NetBSD__
+#include <xen/xenio.h>
+#else
 #include <xen/sys/privcmd.h>
+#endif
 #include <xen/foreign/x86_32.h>
 #include <xen/foreign/x86_64.h>
 
@@ -126,12 +130,19 @@
     int flags, saved_errno;
 
     XGTRC("E\n");
+#ifdef __NetBSD__
+    if ((_dom0_fd=open("/kern/xen/privcmd", O_RDWR)) == -1) {
+        perror("Failed to open /kern/xen/privcmd\n");
+        return -1;
+    }
+#else
     if ((_dom0_fd=open("/dev/xen/privcmd", O_RDWR)) == -1) {
         if ((_dom0_fd=open("/proc/xen/privcmd", O_RDWR)) == -1) {
             perror("Failed to open /dev/xen/privcmd or /proc/xen/privcmd\n");
             return -1;
         }
     }
+#endif
     /* Although we return the file handle as the 'xc handle' the API
      * does not specify / guarentee that this integer is in fact
      * a file handle. Thus we must take responsiblity to ensure
