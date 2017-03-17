$NetBSD: patch-unix_uxpgnt.c,v 1.1 2017/03/17 00:11:48 maya Exp $

BSD setpgrp has parameters. POSIX says it is undefined whether
setpgrp(0,0) == setpgrp() and it should use setpgid.

If this is a problem on glibc, it should support both based
on defines.

--- unix/uxpgnt.c.orig	2017-02-18 17:10:15.000000000 +0000
+++ unix/uxpgnt.c
@@ -270,7 +270,7 @@ void pageant_fork_and_print_env(int reta
         /* Get out of our previous process group, to avoid being
          * blasted by passing signals. But keep our controlling tty,
          * so we can keep checking to see if we still have one. */
-        setpgrp();
+        setpgid(0, 0);
     } else {
         /* Do that, but also leave our entire session and detach from
          * the controlling tty (if any). */
