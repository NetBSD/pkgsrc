$NetBSD: patch-tests_queue-test.c,v 1.1 2019/08/18 16:05:12 nia Exp $

BSD support from FreeBSD

--- tests/queue-test.c.orig	2016-10-22 16:23:10 UTC
+++ tests/queue-test.c
@@ -23,6 +23,8 @@
  * SOFTWARE.
  */
 
+#include "../config.h"
+
 #include <stdlib.h>
 #include <stdint.h>
 #include <stdio.h>
@@ -31,6 +33,9 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <assert.h>
+#ifdef HAVE_SIGNAL_H
+#include <signal.h>
+#endif
 
 #include "wayland-client.h"
 #include "wayland-server.h"
