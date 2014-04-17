$NetBSD: patch-src_help.c,v 1.1 2014/04/17 20:27:33 joerg Exp $

--- src/help.c.orig	2001-12-11 11:21:52.000000000 +0000
+++ src/help.c
@@ -22,7 +22,7 @@
 void cmd_help(int argc, char **argv)
 {
 #ifdef HAVE_LIBREADLINE
-	Function *func;
+	rl_command_func_t *func;
 #endif
 	int i;
 	listitem *li;
@@ -35,7 +35,7 @@ void cmd_help(int argc, char **argv)
 	rl_point=rl_end=0;
 	func = rl_named_function("possible-completions");
 	if(func)
-		func();
+		func(0, 0);
 	else {
 #endif
 		for(i=0; cmds[i].cmd; i++)
