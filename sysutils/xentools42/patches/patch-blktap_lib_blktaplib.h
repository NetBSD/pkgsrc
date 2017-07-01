$NetBSD: patch-blktap_lib_blktaplib.h,v 1.1 2017/07/01 00:40:30 kamil Exp $

--- blktap/lib/blktaplib.h.orig	2014-09-02 06:22:57.000000000 +0000
+++ blktap/lib/blktaplib.h
@@ -34,7 +34,9 @@
 
 #include <xenctrl.h>
 #include <sys/param.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/user.h>
+#endif
 #include <xen/xen.h>
 #include <xen/io/blkif.h>
 #include <xen/io/ring.h>
