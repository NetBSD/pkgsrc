$NetBSD: patch-src_command.c,v 1.1.2.2 2012/10/25 15:05:37 tron Exp $

Avoid de-referencing a NULL pointer on the first command executed(!)

--- src/command.c.orig	2012-02-27 21:58:36.000000000 +0000
+++ src/command.c
@@ -2689,7 +2689,8 @@ rlgets(char *s, size_t n, const char *pr
 	    /* deleting history entries does not work, so suppress adjacent 
 	    duplicates only */
 	    while (previous_history());
-	    if (strcmp(current_history()->line, line) != 0)
+	    if (current_history() != NULL &&
+		strcmp(current_history()->line, line) != 0)
 		add_history(line);
 #  else /* builtin readline */
 	    add_history(line);
