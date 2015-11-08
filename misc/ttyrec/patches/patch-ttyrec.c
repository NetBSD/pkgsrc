$NetBSD: patch-ttyrec.c,v 1.1 2015/11/08 21:02:49 dholland Exp $

- remove union wait

--- ttyrec.c~	2006-06-11 15:52:50.000000000 +0000
+++ ttyrec.c
@@ -203,15 +203,11 @@ doinput()
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
 
