$NetBSD: patch-src_slurmd_common_setproctitle.c,v 1.1 2013/12/06 06:05:30 asau Exp $

--- src/slurmd/common/setproctitle.c.orig	2013-11-04 21:19:15.000000000 +0000
+++ src/slurmd/common/setproctitle.c
@@ -90,7 +90,7 @@
 #include <stdlib.h>
 #include <string.h>
 #endif
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <stdio.h>
 #endif
 #ifndef HAVE_SETPROCTITLE
