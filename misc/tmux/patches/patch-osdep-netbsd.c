$NetBSD: patch-osdep-netbsd.c,v 1.2 2018/11/29 10:51:34 leot Exp $

Implement osdep_get_cwd() via mount_procfs(8) (inspired by osdep-sunos.c).

This was applied upstream via:

 <https://github.com/tmux/tmux/pull/1556>

--- osdep-netbsd.c.orig	2016-01-21 00:00:28.000000000 +0000
+++ osdep-netbsd.c
@@ -23,10 +23,13 @@
 
 #include <errno.h>
 #include <event.h>
+#include <limits.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 
+#include "tmux.h"
+
 #define is_runnable(p) \
         ((p)->p_stat == LSRUN || (p)->p_stat == SIDL)
 #define is_stopped(p) \
@@ -127,6 +130,22 @@ error:
 char *
 osdep_get_cwd(int fd)
 {
+	static char	target[PATH_MAX + 1];
+	char		*path;
+	pid_t		pgrp;
+	ssize_t		n;
+
+	if ((pgrp = tcgetpgrp(fd)) == -1)
+		return (NULL);
+
+	xasprintf(&path, "/proc/%lld/cwd", (long long) pgrp);
+	n = readlink(path, target, sizeof(target) - 1);
+	free(path);
+	if (n > 0) {
+		target[n] = '\0';
+		return (target);
+	}
+
 	return (NULL);
 }
 
