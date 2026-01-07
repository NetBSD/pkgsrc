$NetBSD: patch-src_common_run__command.c,v 1.1 2026/01/07 18:30:07 adam Exp $

NetBSD doesn't have setresgid().

--- src/common/run_command.c.orig	2026-01-07 12:29:48.333473416 +0000
+++ src/common/run_command.c
@@ -328,6 +328,7 @@ static void _run_command_child_pre_exec(
 	 * sync euid -> ruid, egid -> rgid to avoid issues with fork'd
 	 * processes using access() or similar calls.
 	 */
+#if !defined(__APPLE__) && !defined(__NetBSD__)
 	if (setresgid(getegid(), getegid(), -1)) {
 		error("%s: Unable to setresgid()", __func__);
 		_exit(127);
@@ -336,6 +337,7 @@ static void _run_command_child_pre_exec(
 		error("%s: Unable to setresuid()", __func__);
 		_exit(127);
 	}
+#endif
 }
 
 extern void run_command_launcher(int argc, char **argv)
