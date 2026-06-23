$NetBSD: patch-unix_utils_subprocess__waiter.c,v 1.1 2026/06/23 13:23:31 ryoon Exp $

* For SIGCHLD.

--- unix/utils/subprocess_waiter.c.orig	2026-06-23 13:17:12.197007819 +0000
+++ unix/utils/subprocess_waiter.c
@@ -8,6 +8,7 @@
 #include "putty.h"
 #include "tree234.h"
 
+#include <signal.h>
 #include <unistd.h>
 #include <sys/wait.h>
 
