$NetBSD: patch-psinfo.c,v 1.1 2017/06/30 00:31:45 kamil Exp $

--- psinfo.c.orig	2009-03-15 02:15:49.000000000 +0000
+++ psinfo.c
@@ -58,7 +58,9 @@
 #endif	/* __DragonFly_version */
 #include <sys/types.h>
 #include <sys/sysctl.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/user.h>
+#endif
 #endif	/* USE_MACH or USE_KVM */
 
 #include "psinfo.h"
