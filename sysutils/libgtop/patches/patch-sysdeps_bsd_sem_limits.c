$NetBSD: patch-sysdeps_bsd_sem_limits.c,v 1.1 2015/06/06 10:59:57 prlw1 Exp $

struct seminfo is available without the need for _KERNEL.

--- sysdeps/bsd/sem_limits.c.orig	2011-06-01 15:40:47.000000000 +0000
+++ sysdeps/bsd/sem_limits.c
@@ -45,11 +45,13 @@ glibtop_get_sem_limits_p (glibtop *serve
 
 /* #define KERNEL to get declaration of `struct seminfo'. */
 
+#ifndef __NetBSD__
 #if (defined(__FreeBSD__) && (__FreeBSD_version < 410000)) || defined(__bsdi__)
 #define KERNEL 1
 #else
 #define _KERNEL 1
 #endif
+#endif
 
 #include <sys/ipc.h>
 #include <sys/sem.h>
