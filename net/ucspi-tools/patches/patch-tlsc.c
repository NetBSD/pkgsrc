$NetBSD: patch-tlsc.c,v 1.1 2020/11/26 15:52:58 schmonz Exp $

Avoid non-portable execvpe().

--- tlsc.c.orig	2016-09-21 22:05:29.000000000 +0000
+++ tlsc.c
@@ -252,8 +252,8 @@ main(int argc, char *argv[], char *envp[
 
 		if (close(pi[PIPE_WRITE]) < 0) err(EXIT_FAILURE, "close");
 		if (close(po_read) < 0) err(EXIT_FAILURE, "close");
-		execvpe(prog, argv, environ);
-		err(EXIT_FAILURE, "execvpe");
+		execvp(prog, argv);
+		err(EXIT_FAILURE, "execvp");
 	default: break;	/* parent */
 	}
 
