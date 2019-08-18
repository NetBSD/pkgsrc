$NetBSD: patch-tests_test-runner.c,v 1.1 2019/08/18 16:05:12 nia Exp $

BSD support from FreeBSD

--- tests/test-runner.c.orig	2019-03-21 00:55:25.000000000 +0000
+++ tests/test-runner.c
@@ -25,6 +25,12 @@
 
 #define _GNU_SOURCE
 
+#include "../config.h"
+
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -37,13 +43,28 @@
 #include <errno.h>
 #include <limits.h>
 #include <sys/ptrace.h>
+#ifdef HAVE_SYS_PRCTL_H
 #include <sys/prctl.h>
+#endif
+#include <signal.h>
 #ifndef PR_SET_PTRACER
 # define PR_SET_PTRACER 0x59616d61
 #endif
 
 #include "test-runner.h"
 
+#ifndef PTRACE_ATTACH
+#define PTRACE_ATTACH PT_ATTACH
+#endif
+
+#ifndef PTRACE_CONT
+#define PTRACE_CONT PT_CONTINUE
+#endif
+
+#ifndef PTRACE_DETACH
+#define PTRACE_DETACH PT_DETACH
+#endif
+
 /* when set to 1, check if tests are not leaking opened files.
  * It is turned on by default. It can be turned off by
  * WAYLAND_TEST_NO_LEAK_CHECK environment variable. */
@@ -51,7 +72,7 @@ int fd_leak_check_enabled;
 
 /* when this var is set to 0, every call to test_set_timeout() is
  * suppressed - handy when debugging the test. Can be set by
- * WAYLAND_TEST_NO_TIMEOUTS environment variable. */
+ * WAYLAND_TESTS_NO_TIMEOUTS evnironment var */
 static int timeouts_enabled = 1;
 
 /* set to one if the output goes to the terminal */
@@ -239,6 +260,8 @@ is_debugger_attached(void)
 		return 0;
 	}
 
+
+// xxx start here
 	pid = fork();
 	if (pid == -1) {
 		perror("fork");
@@ -259,13 +282,14 @@ is_debugger_attached(void)
 			_exit(1);
 		if (!waitpid(-1, NULL, 0))
 			_exit(1);
-		ptrace(PTRACE_CONT, NULL, NULL);
+		ptrace(PTRACE_CONT, ppid, NULL, NULL);
 		ptrace(PTRACE_DETACH, ppid, NULL, NULL);
 		_exit(0);
 	} else {
 		close(pipefd[0]);
 
 		/* Enable child to ptrace the parent process */
+#if defined(HAVE_PRCTL)
 		rc = prctl(PR_SET_PTRACER, pid);
 		if (rc != 0 && errno != EINVAL) {
 			/* An error prevents us from telling if a debugger is attached.
@@ -275,7 +299,9 @@ is_debugger_attached(void)
 			 */
 			perror("prctl");
 			write(pipefd[1], "-", 1);
-		} else {
+		} else
+#endif
+		{
 			/* Signal to client that parent is ready by passing '+' */
 			write(pipefd[1], "+", 1);
 		}
@@ -295,9 +321,6 @@ int main(int argc, char *argv[])
 	int total, pass;
 	siginfo_t info;
 
-	if (isatty(fileno(stderr)))
-		is_atty = 1;
-
 	if (is_debugger_attached()) {
 		fd_leak_check_enabled = 0;
 		timeouts_enabled = 0;
@@ -336,7 +359,8 @@ int main(int argc, char *argv[])
 		if (pid == 0)
 			run_test(t); /* never returns */
 
-		if (waitid(P_PID, pid, &info, WEXITED)) {
+#ifdef HAVE_WAITID
+		if (waitid(P_PID, 0, &info, WEXITED)) {
 			stderr_set_color(RED);
 			fprintf(stderr, "waitid failed: %m\n");
 			stderr_reset_color();
@@ -367,6 +391,25 @@ int main(int argc, char *argv[])
 
 			break;
 		}
+#else
+               if (waitpid(-1, &status, 0) == -1) {
+                       fprintf(stderr, "waitpid failed: %s\n",
+                               strerror(errno));
+                       abort();
+               }
+
+               fprintf(stderr, "test \"%s\":\t", t->name);
+               if (WIFEXITED(status)) {
+                       fprintf(stderr, "exit status %d", WEXITSTATUS(status));
+                       if (WEXITSTATUS(status) == EXIT_SUCCESS)
+                               success = 1;
+               } else if (WIFSIGNALED(status)) {
+                       fprintf(stderr, "signal %d", WTERMSIG(status));
+               }
+#endif
+
+		if (t->must_fail)
+			success = !success;
 
 		if (success) {
 			pass++;
