$NetBSD: patch-id3ed.cc,v 1.1 2014/04/21 18:17:05 joerg Exp $

--- id3ed.cc.orig	2014-04-20 18:35:33.000000000 +0000
+++ id3ed.cc
@@ -354,7 +354,7 @@ void genreedit(unsigned char &d){
 #ifdef HAVE_LIBREADLINE
 	char *str=NULL;
 	my_rl_default=def;
-	rl_startup_hook=(Function*)set_rl_default;
+	rl_startup_hook=set_rl_default;
 #ifdef HAVE_SET_H
 	(const char *(*)(const char *,int))rl_completion_entry_function=genre_generator;
 #endif
@@ -404,7 +404,7 @@ void stredit(const char * name, int maxl
 	char *str;
 	sprintf(prompt,"%s[max:%i]: ",name,maxlen);
 	my_rl_default=def;
-	rl_startup_hook=(Function*)set_rl_default;
+	rl_startup_hook=set_rl_default;
 	if((str=readline(prompt))){
 		strncpy(buf,str,maxlen);
 		if (*str){
