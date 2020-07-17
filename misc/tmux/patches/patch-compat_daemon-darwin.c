$NetBSD: patch-compat_daemon-darwin.c,v 1.1 2020/07/17 13:21:46 hauke Exp $

No such fanciness in early (ppc) MacOS X

--- compat/daemon-darwin.c.orig	2020-04-14 13:10:35.000000000 +0000
+++ compat/daemon-darwin.c
@@ -49,7 +49,9 @@
 
 #include <mach/mach.h>
 
+#if !defined (__POWERPC__)
 #include <Availability.h>
+#endif /*__POWERPC__*/
 #include <unistd.h>
 
 void daemon_darwin(void);
