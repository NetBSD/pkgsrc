$NetBSD: patch-proc.c,v 1.1 2020/01/09 12:12:17 wiz Exp $

warning: %m is only allowed in syslog(3) like functions [-Wformat=]

use more portable version of setpgrp()
https://github.com/googleprojectzero/halfempty/pull/11

--- proc.c.orig	2019-03-16 17:55:00.000000000 +0000
+++ proc.c
@@ -50,12 +50,12 @@ static void configure_child_limits(gpoin
     // Some of these may fail, not sure what to do.
     for (gint i = 0; i < RLIMIT_NLIMITS; i++) {
         if (setrlimit(i, &kChildLimits[i]) == -1) {
-            g_critical("a call to setrlimit for %u failed(), %m", i);
+            g_critical("a call to setrlimit for %u failed(), %s", i, strerror(errno));
         }
     }
 
     // Make sure we create a new pgrp so that we can kill all subprocesses.
-    setpgrp();
+    setpgid(0, 0);
 
 #ifdef __linux__
     // Try to cleanup if we get killed.
