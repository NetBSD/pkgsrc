$NetBSD: patch-qemu-options.hx,v 1.7 2024/07/10 06:52:48 triaxx Exp $

Fix paths of files mentioned in manpages that are in PKG_SYSCONFDIR.

--- qemu-options.hx.orig	2024-07-10 04:10:09.968279517 +0000
+++ qemu-options.hx
@@ -3219,8 +3219,8 @@ SRST
     Use the network script file to configure it and the network script
     dfile to deconfigure it. If name is not provided, the OS
     automatically provides one. The default network configure script is
-    ``/etc/qemu-ifup`` and the default network deconfigure script is
-    ``/etc/qemu-ifdown``. Use ``script=no`` or ``downscript=no`` to
+    ``@PKG_SYSCONFDIR@/qemu-ifup`` and the default network deconfigure script is
+    ``@PKG_SYSCONFDIR@/qemu-ifdown``. Use ``script=no`` or ``downscript=no`` to
     disable script execution.
 
     If running QEMU as an unprivileged user, use the network helper
