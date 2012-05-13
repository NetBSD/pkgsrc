$NetBSD: patch-src_netbsd.h,v 1.1.1.1 2012/05/13 08:42:20 imil Exp $

Many fixes and addons for conky to work on NetBSD.

--- src/netbsd.h.orig	2010-03-25 17:42:39.000000000 +0000
+++ src/netbsd.h
@@ -12,6 +12,8 @@
 #include <kvm.h>
 #include <nlist.h>
 
+#include <pthread.h>
+
 #include <sys/time.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
@@ -27,10 +29,20 @@
 
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
