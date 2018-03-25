$NetBSD: patch-src_plugins_task_cgroup_task__cgroup__memory.c,v 1.1 2018/03/25 14:55:30 bacon Exp $

# Guard Linuxism?
--- src/plugins/task/cgroup/task_cgroup_memory.c.orig	2018-03-15 18:57:29.000000000 +0000
+++ src/plugins/task/cgroup/task_cgroup_memory.c
@@ -39,7 +39,10 @@
 #include <poll.h>
 #include <signal.h>
 #include <stdlib.h>		/* getenv */
+// Should this be defined(__Linux__)?
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
 #include <sys/eventfd.h>
+#endif
 #include <sys/types.h>
 #include <unistd.h>
 
