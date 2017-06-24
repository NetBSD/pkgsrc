$NetBSD: patch-psutil_arch_bsd_netbsd.c,v 1.7 2017/06/24 08:03:35 adam Exp $

Don't include <sys/user.h> on NetBSD. Include <sys/iostat.h> instead.

--- psutil/arch/bsd/netbsd.c.orig	2017-03-26 08:09:27.000000000 +0000
+++ psutil/arch/bsd/netbsd.c
@@ -22,7 +22,7 @@
 #include <sys/types.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
-#include <sys/user.h>
+#include <sys/iostat.h>
 #include <sys/proc.h>
 #include <sys/swap.h>  // for swap_mem
 #include <signal.h>
