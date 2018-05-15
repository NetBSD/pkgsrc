$NetBSD: patch-psutil_arch_netbsd_specific.c,v 1.1 2018/05/15 22:22:01 minskim Exp $

Don't include <sys/user.h> on NetBSD. Include <sys/iostat.h> instead.

--- psutil/arch/netbsd/specific.c.orig	2018-04-12 08:37:17.000000000 +0000
+++ psutil/arch/netbsd/specific.c
@@ -22,7 +22,7 @@
 #include <sys/types.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
-#include <sys/user.h>
+#include <sys/iostat.h>
 #include <sys/proc.h>
 #include <sys/swap.h>  // for swap_mem
 #include <signal.h>
