$NetBSD: patch-tools_libxc_xc_private.h,v 1.1 2020/08/27 08:22:33 bouyer Exp $

--- ./tools/libxc/xc_private.h.orig	2020-05-27 14:14:10.317819669 +0200
+++ ./tools/libxc/xc_private.h	2020-05-27 14:13:45.466112859 +0200
@@ -38,7 +38,11 @@
 #include <xenforeignmemory.h>
 #include <xendevicemodel.h>
 
+#ifdef __NetBSD__
+#include <xen/xenio.h>
+#else
 #include <xen/sys/privcmd.h>
+#endif
 
 #include <xen-tools/libs.h>
 
