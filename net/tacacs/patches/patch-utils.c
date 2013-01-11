$NetBSD: patch-utils.c,v 1.1 2013/01/11 00:03:30 joerg Exp $

--- utils.c.orig	2013-01-10 22:38:34.000000000 +0000
+++ utils.c
@@ -71,8 +71,7 @@ int size;
     return (p);
 }
 
-tac_exit(status)
-int status;
+void tac_exit(int status)
 {
     if (debug & DEBUG_FORK_FLAG)
 	report(LOG_DEBUG, "exit status=%d", status);
