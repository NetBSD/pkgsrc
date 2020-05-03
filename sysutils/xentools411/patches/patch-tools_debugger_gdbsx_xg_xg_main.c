$NetBSD: patch-tools_debugger_gdbsx_xg_xg_main.c,v 1.1 2020/05/03 08:54:29 bouyer Exp $

--- tools/debugger/gdbsx/xg/xg_main.c.orig	2020-04-30 09:57:45.000000000 +0200
+++ tools/debugger/gdbsx/xg/xg_main.c	2020-04-30 09:58:43.000000000 +0200
@@ -126,12 +126,19 @@
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
