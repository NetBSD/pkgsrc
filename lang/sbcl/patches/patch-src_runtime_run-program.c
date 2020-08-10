$NetBSD: patch-src_runtime_run-program.c,v 1.3 2020/08/10 23:18:52 rjs Exp $

Try to avoid doing the "open /dev/tty, TIOCNOTTY" dance.
Instead, do as on OpenBSD.

--- src/runtime/run-program.c.orig	2020-07-30 19:30:03.000000000 +0000
+++ src/runtime/run-program.c
@@ -29,7 +29,7 @@
 #include <dirent.h>
 #include "interr.h" // for lose()
 
-#ifdef LISP_FEATURE_OPENBSD
+#if defined(LISP_FEATURE_OPENBSD) || defined(LISP_FEATURE_NETBSD)
 #include <util.h>
 #endif
 
@@ -57,7 +57,7 @@ int set_noecho(int fd)
     return 1;
 }
 
-#if defined(LISP_FEATURE_OPENBSD)
+#if defined(LISP_FEATURE_OPENBSD) || defined(LISP_FEATURE_NETBSD)
 
 int
 set_pty(char *pty_name)
@@ -70,7 +70,7 @@ set_pty(char *pty_name)
     return (set_noecho(STDIN_FILENO));
 }
 
-#else /* !LISP_FEATURE_OPENBSD */
+#else /* !LISP_FEATURE_OPENBSD && !LISP_FEATURE_NETBSD */
 
 int
 set_pty(char *pty_name)
@@ -94,7 +94,7 @@ set_pty(char *pty_name)
     return (0);
 }
 
-#endif /* !LISP_FEATURE_OPENBSD */
+#endif /* !LISP_FEATURE_OPENBSD && !LISP_FEATURE_NETBSD */
 
 void closefrom_fallback(int lowfd)
 {
@@ -220,7 +220,8 @@ int spawn(char *program, char *argv[], i
      * share stdin with our parent. In the latter case we claim
      * control of the terminal. */
     if (sin >= 0) {
-#if defined(LISP_FEATURE_HPUX) || defined(LISP_FEATURE_OPENBSD)
+#if defined(LISP_FEATURE_HPUX) || defined(LISP_FEATURE_OPENBSD) || \
+	defined(LISP_FEATURE_NETBSD)
       setsid();
 #elif defined(LISP_FEATURE_DARWIN)
       setpgid(0, getpid());
