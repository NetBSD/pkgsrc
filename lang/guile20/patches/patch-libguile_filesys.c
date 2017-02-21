$NetBSD: patch-libguile_filesys.c,v 1.3 2017/02/21 15:55:28 gdt Exp $

When using mkostemp (an interface not defined by POSIX), restrict
flags to the set defined by the documentation of particular operating
systems.

See https://debbugs.gnu.org/cgi/bugreport.cgi?bug=24862#23 for discussion.

This patch has not yet been sent upstream.

--- libguile/filesys.c.orig	2016-12-15 00:03:33.000000000 +0000
+++ libguile/filesys.c
@@ -1486,6 +1486,15 @@ SCM_DEFINE (scm_i_mkstemp, "mkstemp!", 1
       mode_bits = scm_i_mode_bits (mode);
     }
 
+#ifdef __APPLE__
+  /* https://debbugs.gnu.org/cgi/bugreport.cgi?bug=24862#23 */
+  open_flags &= O_APPEND|O_SHLOCK|O_EXLOCK|O_CLOEXEC;
+#endif
+#ifdef __NetBSD__
+  /* Restrict to list of flags documented in man page. */
+  open_flags &= O_APPEND|O_DIRECT|O_SHLOCK|O_EXLOCK|O_SYNC|O_CLOEXEC;
+#endif
+
   SCM_SYSCALL (rv = mkostemp (c_tmpl, open_flags));
   if (rv == -1)
     SCM_SYSERROR;
