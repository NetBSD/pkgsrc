$NetBSD: patch-osdep-darwin.c,v 1.4 2021/04/17 10:11:04 leot Exp $

No such fanciness in early (ppc) MacOS X

--- osdep-darwin.c.orig	2021-03-02 12:07:17.000000000 +0000
+++ osdep-darwin.c
@@ -19,8 +19,10 @@
 #include <sys/types.h>
 #include <sys/sysctl.h>
 
+#if !defined (__POWERPC__)
 #include <Availability.h>
 #include <libproc.h>
+#endif /*__POWERPC__*/
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
@@ -38,7 +40,9 @@ struct event_base	*osdep_event_init(void
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
@@ -72,6 +76,7 @@ osdep_get_name(int fd, __unused char *tt
 char *
 osdep_get_cwd(int fd)
 {
+#if !defined (__POWERPC__)
 	static char			wd[PATH_MAX];
 	struct proc_vnodepathinfo	pathinfo;
 	pid_t				pgrp;
@@ -86,6 +91,7 @@ osdep_get_cwd(int fd)
 		strlcpy(wd, pathinfo.pvi_cdir.vip_path, sizeof wd);
 		return (wd);
 	}
+#endif /*__POWERPC__*/
 	return (NULL);
 }
 
