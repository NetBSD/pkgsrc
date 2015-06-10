$NetBSD: patch-src_main.c,v 1.1 2015/06/10 14:57:52 joerg Exp $

--- src/main.c.orig	2015-06-09 23:23:22.000000000 +0000
+++ src/main.c
@@ -594,18 +594,18 @@ char **find_command(char *name){
 
 
 void initrl(void){
-  rl_attempted_completion_function=(CPPFunction *)completion;
+  rl_attempted_completion_function=completion;
 }
 
 
-char **completion(char *text, int start, int end){
+char **completion(const char *text, int start, int end){
   char **matches=(char **)NULL;
   
   if(!start) matches=(char **)completion_matches(text, match);
   return matches;
 }
 
-char *match(char *text, int state){
+char *match(const char *text, int state){
   static int i, len;
   
   if(!state){
