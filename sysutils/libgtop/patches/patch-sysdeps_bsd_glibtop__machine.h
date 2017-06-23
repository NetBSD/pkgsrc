$NetBSD: patch-sysdeps_bsd_glibtop__machine.h,v 1.1 2017/06/23 16:42:05 kamil Exp $

<sys/user.h> in this context is freebsdism.

--- sysdeps/bsd/glibtop_machine.h.orig	2011-06-01 15:40:47.000000000 +0000
+++ sysdeps/bsd/glibtop_machine.h
@@ -27,7 +27,9 @@
 #include <kvm.h>
 #include <sys/dkstat.h>
 #include <time.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/user.h>
+#endif
 #include <sys/types.h>
 #include <sys/sysctl.h>
 
