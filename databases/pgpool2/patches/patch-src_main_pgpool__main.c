$NetBSD: patch-src_main_pgpool__main.c,v 1.1 2021/04/28 09:18:55 wiz Exp $

--- src/main/pgpool_main.c.orig	2021-04-24 00:39:53.017132316 +0300
+++ src/main/pgpool_main.c	2021-04-24 00:40:56.172455323 +0300
@@ -33,10 +33,8 @@
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/wait.h>
-
-#ifdef  __FreeBSD__
+#include <sys/syslog.h>
 #include <netinet/in.h>
-#endif
 
 #include "pool.h"
 #include "version.h"
