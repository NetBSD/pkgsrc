$NetBSD: patch-include_command.h,v 1.1 2015/06/10 14:57:52 joerg Exp $

--- include/command.h.orig	2015-06-09 23:23:54.000000000 +0000
+++ include/command.h
@@ -10,6 +10,6 @@ char *commands[] = {
 };              
 
 void initrl(void);
-char **completion(char *, int, int);
-char *match(char *, int);
+char **completion(const char *, int, int);
+char *match(const char *, int);
 char **find_command(char *);
