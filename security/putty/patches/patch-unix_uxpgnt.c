$NetBSD: patch-unix_uxpgnt.c,v 1.3 2020/07/30 13:32:33 tnn Exp $

BSD setpgrp has parameters. POSIX says it is undefined whether
setpgrp(0,0) == setpgrp() and it should use setpgid.

--- unix/uxpgnt.c.orig	2020-06-21 17:30:49.000000000 +0000
+++ unix/uxpgnt.c
@@ -240,7 +240,7 @@ void pageant_fork_and_print_env(bool ret
         /* Get out of our previous process group, to avoid being
          * blasted by passing signals. But keep our controlling tty,
          * so we can keep checking to see if we still have one. */
-        setpgrp();
+        setpgid(0, 0);
     } else {
         /* Do that, but also leave our entire session and detach from
          * the controlling tty (if any). */
