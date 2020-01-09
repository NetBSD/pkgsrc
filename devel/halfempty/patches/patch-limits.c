$NetBSD: patch-limits.c,v 1.1 2020/01/09 12:12:17 wiz Exp $

%m is only allowed in syslog(3) like functions [-Wformat=]
https://github.com/googleprojectzero/halfempty/pull/11

--- limits.c.orig	2019-03-16 17:55:00.000000000 +0000
+++ limits.c
@@ -25,6 +25,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <assert.h>
+#include <errno.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <sys/time.h>
@@ -127,7 +128,7 @@ static void __attribute__((constructor))
 
     for (gint i = 0; i < RLIMIT_NLIMITS; i++) {
         if (getrlimit(i, &kChildLimits[i]) != 0) {
-            g_warning("failed to getrlimit for %u, %m", i);
+            g_warning("failed to getrlimit for %u, %s", i, strerror(errno));
         }
 
         g_debug("Configured rlimit %s => { %llu, %llu }",
