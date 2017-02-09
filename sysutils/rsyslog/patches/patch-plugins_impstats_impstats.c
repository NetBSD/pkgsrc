$NetBSD: patch-plugins_impstats_impstats.c,v 1.1 2017/02/09 00:18:36 joerg Exp $

--- plugins/impstats/impstats.c.orig	2017-02-08 21:16:20.608978307 +0000
+++ plugins/impstats/impstats.c
@@ -30,9 +30,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/uio.h>
-#if defined(__FreeBSD__)
 #include <sys/stat.h>
-#endif
 #include <errno.h>
 #include <sys/time.h>
 #include <sys/resource.h>
