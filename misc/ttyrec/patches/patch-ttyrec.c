$NetBSD: patch-ttyrec.c,v 1.2 2016/05/31 08:13:45 leot Exp $

- add <signal.h> (needed by kill(2))
- use <util.h> on NetBSD, OpenBSD and Mac OS X
- remove union wait

--- ttyrec.c.orig	2006-06-11 15:52:50.000000000 +0000
+++ ttyrec.c
@@ -49,6 +49,7 @@
 #include <sys/time.h>
 #include <sys/file.h>
 #include <sys/signal.h>
+#include <signal.h>
 #include <stdio.h>
 #include <time.h>
 #include <unistd.h>
@@ -71,8 +72,12 @@
 #define _(FOO) FOO
 
 #ifdef HAVE_openpty
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#include <util.h>
+#else
 #include <libutil.h>
 #endif
+#endif
 
 #if defined(SVR4) && !defined(CDEL)
 #if defined(_POSIX_VDISABLE)
@@ -203,15 +208,11 @@ doinput()
 void
 finish()
 {
-#if defined(SVR4)
 	int status;
-#else /* !SVR4 */
-	union wait status;
-#endif /* !SVR4 */
 	register int pid;
 	register int die = 0;
 
-	while ((pid = wait3((int *)&status, WNOHANG, 0)) > 0)
+	while ((pid = wait3(&status, WNOHANG, 0)) > 0)
 		if (pid == child)
 			die = 1;
 
