$NetBSD: patch-get__my__path__freebsd.c,v 1.1 2024/09/21 13:14:58 abs Exp $

Use sysctl rather than /proc

--- get_my_path_freebsd.c.orig	2014-10-22 00:46:49.000000000 +0000
+++ get_my_path_freebsd.c
@@ -18,19 +18,18 @@
  */
 
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #include <unistd.h>
-#include <limits.h>
-#include <stdio.h>
 
 void
 get_my_path(char *exe, size_t maxLen)
 {
-    char proc[64];
+    int mib[4] = {
+        CTL_KERN,
+        KERN_PROC,
+        KERN_PROC_PATHNAME,
+        getpid()
+    };
 
-    snprintf(proc, sizeof(proc), "/proc/%d/file", getpid());
-
-    int err = readlink(proc, exe, maxLen - 1);
-
-    exe[err > 0 ? err : 0] = '\0';
+    sysctl(mib, 4, exe, &maxLen, NULL, 0);
 }
-
