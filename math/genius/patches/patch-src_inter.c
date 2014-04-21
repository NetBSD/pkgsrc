$NetBSD: patch-src_inter.c,v 1.1 2014/04/21 18:17:35 joerg Exp $

--- src/inter.c.orig	2014-04-20 18:19:20.000000000 +0000
+++ src/inter.c
@@ -366,6 +366,5 @@ void
 init_inter(void)
 {
 	rl_readline_name = "Genius";
-	rl_attempted_completion_function =
-		(CPPFunction *)tab_completion;
+	rl_attempted_completion_function = tab_completion;
 }
