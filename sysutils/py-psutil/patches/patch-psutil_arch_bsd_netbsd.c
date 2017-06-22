$NetBSD: patch-psutil_arch_bsd_netbsd.c,v 1.6 2017/06/22 22:01:47 kamil Exp $

Don't include <sys/user.h> on NetBSD.

--- psutil/arch/bsd/netbsd.c.orig	2017-03-26 08:09:27.000000000 +0000
+++ psutil/arch/bsd/netbsd.c
@@ -22,7 +22,6 @@
 #include <sys/types.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
-#include <sys/user.h>
 #include <sys/proc.h>
 #include <sys/swap.h>  // for swap_mem
 #include <signal.h>
