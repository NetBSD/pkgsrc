$NetBSD: patch-unix_uxpgnt.c,v 1.2 2017/03/17 11:55:53 maya Exp $

BSD setpgrp has parameters. POSIX says it is undefined whether
setpgrp(0,0) == setpgrp() and it should use setpgid.

Use setpgid without parameters on non-BSD

--- unix/uxpgnt.c.orig	2017-02-18 17:10:15.000000000 +0000
+++ unix/uxpgnt.c
@@ -270,7 +270,11 @@ void pageant_fork_and_print_env(int reta
         /* Get out of our previous process group, to avoid being
          * blasted by passing signals. But keep our controlling tty,
          * so we can keep checking to see if we still have one. */
-        setpgrp();
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
+        setpgid(0, 0);
+#else
+        setpgid();
+#endif
     } else {
         /* Do that, but also leave our entire session and detach from
          * the controlling tty (if any). */
