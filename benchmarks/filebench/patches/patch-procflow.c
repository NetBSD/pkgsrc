$NetBSD: patch-procflow.c,v 1.1.1.1 2012/07/02 17:43:16 asau Exp $

--- procflow.c.orig	2011-09-06 17:17:45.000000000 +0000
+++ procflow.c
@@ -402,7 +402,11 @@ procflow_createnwait(void *unused)
 		}
 #else /* HAVE_WAITID */
 		/* child did not exit, but got a signal, so just continue waiting */
-		if (WIFSTOPPED(status) || WIFCONTINUED(status))
+		if (WIFSTOPPED(status)
+#if defined(WIFCONTINUED)
+		    || WIFCONTINUED(status)
+#endif
+			)
 			continue;
 
 		if (WIFEXITED(status)) {
