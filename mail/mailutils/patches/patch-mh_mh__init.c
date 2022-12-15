$NetBSD: patch-mh_mh__init.c,v 1.1 2022/12/15 13:58:02 vins Exp $

Define TIOCGWINSZ ioctl on SunOS.

--- mh/mh_init.c.orig	2022-02-12 15:20:43.000000000 +0000
+++ mh/mh_init.c
@@ -29,6 +29,9 @@
 #include <fcntl.h>
 #include <fnmatch.h>
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/ttold.h>
+#endif
 
 void
 mh_init (void)
