A
$NetBSD: patch-libvisual_lv__os.c,v 1.1 2019/10/23 00:13:40 maya Exp $
macos ox has header sched.h but does not provide the realtime function:

int sched_setscheduler(pid_t, int, const struct sched_param *);
(optional according to open group).

so it is necessary to force real time defined functions in the package are not supported on apple system.

(PR pkg/54416)

--- libvisual/lv_os.c.orig     2006-01-26 15:13:37.000000000 +0000
+++ libvisual/lv_os.c
@@ -31,7 +31,9 @@
 #ifdef HAVE_SCHED_H
 # include <sched.h>
 # include <sys/types.h>
+#ifndef __APPLE__
 # define HAVE_SCHED 1
+#endif
 #elif defined HAVE_SYS_SCHED_H
 # include <sys/sched.h>
 # include <sys/types.h>
