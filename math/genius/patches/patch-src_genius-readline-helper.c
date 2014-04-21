$NetBSD: patch-src_genius-readline-helper.c,v 1.1 2014/04/21 18:17:35 joerg Exp $

--- src/genius-readline-helper.c.orig	2014-04-20 18:20:05.000000000 +0000
+++ src/genius-readline-helper.c
@@ -104,7 +104,7 @@ plugin_generator (const char *text, int 
 /* Note: keep in sync with inter.c */
 /* FIXME: make this common */
 static char **
-tab_completion (char *text, int start, int end)
+tab_completion (const char *text, int start, int end)
 {
 	char *p;
 	for(p=rl_line_buffer;*p==' ' || *p=='\t';p++)
@@ -182,8 +182,7 @@ main(int argc, char *argv[])
 	rl_catch_sigwinch = 1;
 	rl_terminal_name = "xterm";
 	rl_readline_name = "Genius";
-	rl_attempted_completion_function =
-		(CPPFunction *)tab_completion;
+	rl_attempted_completion_function = tab_completion;
 
 	while(fgets(buf,4096,infp)) {
 		int count;
