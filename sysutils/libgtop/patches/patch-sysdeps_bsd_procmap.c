$NetBSD: patch-sysdeps_bsd_procmap.c,v 1.1 2017/06/23 16:42:05 kamil Exp $

<sys/user.h> in this context is freebsdism.

--- sysdeps/bsd/procmap.c.orig	2011-06-01 15:40:47.000000000 +0000
+++ sysdeps/bsd/procmap.c
@@ -58,7 +58,7 @@
 #include <ufs/ufs/inode.h>
 
 #include <sys/ucred.h>
-#if (!defined __OpenBSD__) && (!defined __bsdi__)
+#if (!defined __OpenBSD__) && (!defined __bsdi__) && (!defined __NetBSD__)
 #include <sys/user.h>
 #endif
 #include <sys/sysctl.h>
