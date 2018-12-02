$NetBSD: patch-src_lib-master_test-event-stats.c,v 1.1 2018/12/02 04:45:00 schmonz Exp $

Provide declarations for kill() and SIGKILL.

--- src/lib-master/test-event-stats.c.orig	2018-11-23 11:06:49.000000000 +0000
+++ src/lib-master/test-event-stats.c
@@ -12,6 +12,7 @@
 #include "stats-client.h"
 #include "test-common.h"
 #include <fcntl.h>
+#include <signal.h>
 #include <unistd.h>
 #include <sys/socket.h>
 #include <sys/un.h>
