$NetBSD: patch-examples_loadables_push.c,v 1.1 2019/01/21 09:03:44 leot Exp $

Match declaration of dollar_dollar_pid in variables.h.

--- examples/loadables/push.c.orig	2017-06-20 14:54:52.000000000 +0000
+++ examples/loadables/push.c
@@ -35,7 +35,7 @@
 extern int errno;
 #endif
 
-extern int dollar_dollar_pid;
+extern pid_t dollar_dollar_pid;
 extern int last_command_exit_value;
 
 int
