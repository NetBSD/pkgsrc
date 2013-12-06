$NetBSD: patch-src_srun_libsrun_launch.c,v 1.1 2013/12/06 06:05:30 asau Exp $

--- src/srun/libsrun/launch.c.orig	2013-11-04 21:19:15.000000000 +0000
+++ src/srun/libsrun/launch.c
@@ -36,7 +36,7 @@
 #include <stdlib.h>
 #include <fcntl.h>
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <signal.h>
 #endif
 
