$NetBSD: patch-src_runtime_run-program.c,v 1.1 2019/10/12 09:47:40 he Exp $

Try to avoid doing the "open /dev/tty, TIOCNOTTY" dance.
Instead, do as on OpenBSD.

--- src/runtime/run-program.c.orig	2019-10-11 11:45:06.733855374 +0000
+++ src/runtime/run-program.c
@@ -30,7 +30,7 @@
 #include <termios.h>
 #include <errno.h>
 
-#ifdef LISP_FEATURE_OPENBSD
+#if defined(LISP_FEATURE_OPENBSD) || defined(LISP_FETURE_NETBSD)
 #include <util.h>
 #endif
 
@@ -58,7 +58,7 @@ int set_noecho(int fd)
     return 1;
 }
 
-#if defined(LISP_FEATURE_OPENBSD)
+#if defined(LISP_FEATURE_OPENBSD) || defined(LISP_FEATURE_NETBSD)
 
 int
 set_pty(char *pty_name)
@@ -71,7 +71,7 @@ set_pty(char *pty_name)
     return (set_noecho(STDIN_FILENO));
 }
 
-#else /* !LISP_FEATURE_OPENBSD */
+#else /* !LISP_FEATURE_OPENBSD && !LISP_FEATURE_NETBSD */
 
 int
 set_pty(char *pty_name)
@@ -95,7 +95,7 @@ set_pty(char *pty_name)
     return (0);
 }
 
-#endif /* !LISP_FEATURE_OPENBSD */
+#endif /* !LISP_FEATURE_OPENBSD && !LISP_FEATURE_NETBSD */
 
 int wait_for_exec(int pid, int channel[2]) {
     if ((-1 != pid) && (-1 != channel[1])) {
@@ -164,7 +164,8 @@ int spawn(char *program, char *argv[], i
      * share stdin with our parent. In the latter case we claim
      * control of the terminal. */
     if (sin >= 0) {
-#if defined(LISP_FEATURE_HPUX) || defined(LISP_FEATURE_OPENBSD)
+#if defined(LISP_FEATURE_HPUX) || defined(LISP_FEATURE_OPENBSD) || \
+	defined(LISP_FEATURE_NETBSD)
       setsid();
 #elif defined(LISP_FEATURE_DARWIN)
       setpgid(0, getpid());
