$NetBSD: patch-src_ck-sysdeps-netbsd.c,v 1.1 2017/06/22 22:09:17 kamil Exp $

Don't include <sys/user.h> on NetBSD.

--- src/ck-sysdeps-netbsd.c.orig	2016-03-19 15:14:24.000000000 +0000
+++ src/ck-sysdeps-netbsd.c
@@ -36,7 +36,6 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/sysctl.h>
-#include <sys/user.h>
 #include <sys/ioctl.h>
 
 #include <dev/wscons/wsdisplay_usl_io.h>
