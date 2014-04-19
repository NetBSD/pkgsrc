$NetBSD: patch-liboop_test-oop.c,v 1.1 2014/04/19 14:59:35 joerg Exp $

--- liboop/test-oop.c.orig	2014-04-19 13:45:30.000000000 +0000
+++ liboop/test-oop.c
@@ -160,7 +160,7 @@ static void *stop_data(oop_source *sourc
 
 #ifdef HAVE_READLINE
 
-static void on_readline(const char *input) {
+static void on_readline(char *input) {
 	if (NULL == input)
 		puts("\rreadline: EOF");
 	else {
@@ -179,8 +179,8 @@ static void *stop_readline(oop_source *s
 
 static void add_readline(oop_source *src) {
 	rl_callback_handler_install(
-		(char *) "> ", /* readline isn't const-correct */
-		(VFunction *) on_readline);
+		"> ",
+		on_readline);
 	oop_readline_register(src);
 	src->on_signal(src,SIGQUIT,stop_readline,NULL);
 }
