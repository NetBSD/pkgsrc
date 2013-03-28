$NetBSD: patch-faxrec.c,v 1.1 2013/03/28 21:17:57 joerg Exp $

--- faxrec.c.orig	2013-03-28 20:03:52.000000000 +0000
+++ faxrec.c
@@ -22,6 +22,10 @@
 #include <sys/times.h>
 #include <sys/stat.h>
 
+#ifdef __NetBSD__
+#include <utmpx.h>
+#endif
+
 #ifndef sunos4
 #include <sys/ioctl.h>
 #endif
