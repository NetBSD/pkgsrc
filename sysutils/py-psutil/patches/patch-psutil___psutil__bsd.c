$NetBSD: patch-psutil___psutil__bsd.c,v 1.8 2017/06/22 22:01:47 kamil Exp $

Don't include <sys/user.h> on every BSD.
It's absent on NetBSD and unused on OpenBSD.

--- psutil/_psutil_bsd.c.orig	2017-03-26 08:09:27.000000000 +0000
+++ psutil/_psutil_bsd.c
@@ -30,7 +30,9 @@
 #include <sys/types.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/user.h>
+#endif
 #include <sys/proc.h>
 #include <sys/file.h>
 #include <sys/socket.h>
