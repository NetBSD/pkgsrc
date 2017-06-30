$NetBSD: patch-src_netbsd.h,v 1.2 2017/06/30 00:23:03 kamil Exp $

Many fixes and addons for conky to work on NetBSD.

--- src/netbsd.h.orig	2010-03-25 17:42:39.000000000 +0000
+++ src/netbsd.h
@@ -12,10 +12,11 @@
 #include <kvm.h>
 #include <nlist.h>
 
+#include <pthread.h>
+
 #include <sys/time.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
-#include <sys/user.h>
 #include <sys/socket.h>
 #include <sys/swap.h>
 #include <sys/sched.h>
@@ -27,10 +28,20 @@
 
 #include <machine/param.h>
 
+#include <prop/proplib.h>
+
 #include "conky.h"
 #include "common.h"
 
+#define _DEV_SYSMON	"/dev/sysmon"
+
 int get_entropy_avail(unsigned int *);
 int get_entropy_poolsize(unsigned int *);
 
+void sysmon_open(void);
+void sysmon_close(void);
+
+kvm_t			*kd;
+extern int		sysmon_fd;
+
 #endif /*NETBSD_H_*/
