$NetBSD: patch-src_polkit_polkitunixprocess.c,v 1.4 2018/05/14 09:30:35 jperkin Exp $

Fix SunOS includes.

--- src/polkit/polkitunixprocess.c.orig	2018-03-23 15:09:30.000000000 +0000
+++ src/polkit/polkitunixprocess.c
@@ -24,6 +24,11 @@
 #endif
 
 #include <sys/types.h>
+#ifdef HAVE_SOLARIS
+#include <sys/stat.h>
+#include <fcntl.h>
+#include <procfs.h>
+#endif
 #ifdef HAVE_FREEBSD
 #include <sys/param.h>
 #include <sys/sysctl.h>
