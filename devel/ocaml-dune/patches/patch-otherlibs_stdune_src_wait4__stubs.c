$NetBSD: patch-otherlibs_stdune_src_wait4__stubs.c,v 1.1 2026/04/14 09:15:00 jperkin Exp $

Handle wait4() quirk on SunOS.  Reported upstream as
https://github.com/ocaml/dune/issues/14182

--- otherlibs/stdune/src/wait4_stubs.c.orig	2026-04-01 17:26:23.000000000 +0000
+++ otherlibs/stdune/src/wait4_stubs.c
@@ -76,8 +76,14 @@ value dune_wait4(value v_pid, value flag
   struct rusage ru;
 
   caml_enter_blocking_section();
+  // On Solaris/illumos, wait4(-1, ...) semantics are different, so in the
+  // pid == -1 case use 0 and effectively act the same as wait3().
+#if defined(__sun)
+  pid = wait4(pid == -1 ? 0 : pid, &status, cv_flags, &ru);
+#else
   // returns the pid of the terminated process, or -1 on error
   pid = wait4(pid, &status, cv_flags, &ru);
+#endif
   int wait_errno = errno;
   time_ns = dune_clock_gettime_ns();
   caml_leave_blocking_section();
