$NetBSD: patch-src_common_slurm__jobacct__gather.c,v 1.1 2013/12/06 06:05:30 asau Exp $

--- src/common/slurm_jobacct_gather.c.orig	2013-11-04 21:19:15.000000000 +0000
+++ src/common/slurm_jobacct_gather.c
@@ -47,7 +47,7 @@
  *  	 Morris Jette, et al.
 \*****************************************************************************/
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <signal.h>
 #endif
 #include <pthread.h>
