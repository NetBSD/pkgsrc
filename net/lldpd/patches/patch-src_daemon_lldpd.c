$NetBSD: patch-src_daemon_lldpd.c,v 1.1 2013/05/09 05:42:53 mef Exp $

Add DragonFly support.

--- src/daemon/lldpd.c~	2013-04-13 17:21:43.000000000 +0900
+++ src/daemon/lldpd.c	2013-05-09 13:53:17.252539000 +0900
@@ -40,6 +40,7 @@
 #if defined HOST_OS_FREEBSD || \
     defined HOST_OS_OPENBSD || \
     defined HOST_OS_NETBSD  || \
+    defined HOST_OS_DRAGONFLY  || \
     defined HOST_OS_OSX
 # include <sys/param.h>
 # include <sys/sysctl.h>
@@ -873,7 +874,7 @@ lldpd_forwarding_enabled(void)
 			rc = 1;
 		close(f);
 	}
-#elif defined HOST_OS_FREEBSD || defined HOST_OS_OPENBSD || defined HOST_OS_NETBSD || defined HOST_OS_OSX
+#elif defined HOST_OS_FREEBSD || defined HOST_OS_OPENBSD || defined HOST_OS_NETBSD || defined HOST_OS_OSX || defined HOST_OS_DRAGONFLY
 	int n, mib[4] = {
 		CTL_NET,
 		PF_INET,
