$NetBSD: patch-osdep-darwin.c,v 1.3 2020/07/17 13:21:46 hauke Exp $

No such fanciness in early (ppc) MacOS X

--- osdep-darwin.c.orig	2020-05-04 08:06:23.000000000 +0000
+++ osdep-darwin.c
@@ -19,9 +19,11 @@
 #include <sys/types.h>
 #include <sys/sysctl.h>
 
+#if !defined (__POWERPC__)
 #include <Availability.h>
-#include <event.h>
 #include <libproc.h>
+#endif /*__POWERPC__*/
+#include <event.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
@@ -37,7 +39,9 @@ struct event_base	*osdep_event_init(void
 char *
 osdep_get_name(int fd, __unused char *tty)
 {
-#ifdef __MAC_10_7
+#if defined (__POWERPC__)
+        return (NULL);
+#elif defined (__MAC_10_7)
 	struct proc_bsdshortinfo	bsdinfo;
 	pid_t				pgrp;
 	int				ret;
@@ -71,6 +75,7 @@ osdep_get_name(int fd, __unused char *tt
 char *
 osdep_get_cwd(int fd)
 {
+#if !defined (__POWERPC__)
 	static char			wd[PATH_MAX];
 	struct proc_vnodepathinfo	pathinfo;
 	pid_t				pgrp;
@@ -85,6 +90,7 @@ osdep_get_cwd(int fd)
 		strlcpy(wd, pathinfo.pvi_cdir.vip_path, sizeof wd);
 		return (wd);
 	}
+#endif /*__POWERPC__*/
 	return (NULL);
 }
 
