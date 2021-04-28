$NetBSD: patch-src_watchdog_wd__escalation.c,v 1.2 2021/04/28 09:18:55 wiz Exp $

Add sys/wait.h unconditionally, same as other source files.

--- src/watchdog/wd_escalation.c.orig	2021-04-24 00:49:41.737572235 +0300
+++ src/watchdog/wd_escalation.c	2021-04-24 00:49:56.140555487 +0300
@@ -26,10 +26,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <errno.h>
-
-#ifdef __FreeBSD__
 #include <sys/wait.h>
-#endif
 
 #include "utils/pool_signal.h"
 #include "utils/elog.h"
