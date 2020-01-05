$NetBSD: patch-tests_test-runner.c,v 1.2 2020/01/05 19:30:48 nia Exp $

NetBSD support

--- tests/test-runner.c.orig	2019-03-21 00:55:25.000000000 +0000
+++ tests/test-runner.c
@@ -31,19 +31,34 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <sys/stat.h>
+#include <signal.h>
 #include <string.h>
 #include <assert.h>
 #include <dlfcn.h>
 #include <errno.h>
 #include <limits.h>
 #include <sys/ptrace.h>
+#if defined(HAVE_PRCTL)
 #include <sys/prctl.h>
+#endif
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
@@ -259,12 +274,13 @@ is_debugger_attached(void)
 			_exit(1);
 		if (!waitpid(-1, NULL, 0))
 			_exit(1);
-		ptrace(PTRACE_CONT, NULL, NULL);
+		ptrace(PTRACE_CONT, ppid, NULL, NULL);
 		ptrace(PTRACE_DETACH, ppid, NULL, NULL);
 		_exit(0);
 	} else {
 		close(pipefd[0]);
 
+#if defined(HAVE_PRCTL)
 		/* Enable child to ptrace the parent process */
 		rc = prctl(PR_SET_PTRACER, pid);
 		if (rc != 0 && errno != EINVAL) {
@@ -275,7 +291,9 @@ is_debugger_attached(void)
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
