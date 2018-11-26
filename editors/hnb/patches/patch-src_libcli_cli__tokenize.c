$NetBSD: patch-src_libcli_cli__tokenize.c,v 1.1 2018/11/26 09:15:53 fox Exp $

Replaced char * with unsigned char * since this is how the function
is used, also prevents compiler from spweing out warnings.

--- src/libcli/cli_tokenize.c.orig	2003-03-14 03:23:22.000000000 +0000
+++ src/libcli/cli_tokenize.c
@@ -68,14 +68,14 @@ typedef struct {
 
 #ifdef TESTit
 #define cli_getstring dummy_get_variable
-static char * dummy_get_variable(char *name){
+static char * dummy_get_variable(unsigned char *name){
 	static char *dummy="<variable expansion not implemented yet>";
 	return dummy;
 }
 #endif
 
 #ifndef TESTit
-char *cli_getstring(char *variable);
+char *cli_getstring(unsigned char *variable);
 #endif
 
 static rule_entry state_table[s_end][max_rules];
