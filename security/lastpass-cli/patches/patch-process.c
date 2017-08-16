$NetBSD: patch-process.c,v 1.1 2017/08/16 15:18:24 jperkin Exp $

Support pid_to_cmd on SunOS.

--- process.c.orig	2017-06-28 12:50:49.000000000 +0000
+++ process.c
@@ -83,6 +83,13 @@ static int pid_to_cmd(pid_t pid, char *c
 	xasprintf(&proc, "/proc/%lu/exe", (unsigned long)pid);
 	return readlink(proc, cmd, cmd_size - 1);
 }
+#elif defined(__sun)
+static int pid_to_cmd(pid_t pid, char *cmd, size_t cmd_size)
+{
+	_cleanup_free_ char *proc;
+	xasprintf(&proc, "/proc/%lu/path/a.out", (unsigned long)pid);
+	return readlink(proc, cmd, cmd_size - 1);
+}
 #elif defined(__APPLE__) && defined(__MACH__)
 static int pid_to_cmd(pid_t pid, char *cmd, size_t cmd_size)
 {
