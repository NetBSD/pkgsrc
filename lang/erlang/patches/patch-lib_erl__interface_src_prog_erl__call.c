$NetBSD: patch-lib_erl__interface_src_prog_erl__call.c,v 1.1 2024/05/27 19:07:50 riastradh Exp $

Fix ctype(3) misuse.

--- lib/erl_interface/src/prog/erl_call.c.orig	2024-03-06 15:30:18.000000000 +0000
+++ lib/erl_interface/src/prog/erl_call.c
@@ -852,8 +852,8 @@ static int do_connect(ei_cnode *ec, char
     return fd;
 } /* do_connect */
 
-#define SKIP_SPACE(s) while(isspace((int)*(s))) (s)++
-#define EAT(s) while (!isspace((int)*(s)) && (*(s) != '\0')) (s)++
+#define SKIP_SPACE(s) while(isspace((unsigned char)*(s))) (s)++
+#define EAT(s) while (!isspace((unsigned char)*(s)) && (*(s) != '\0')) (s)++
 
 static void split_apply_string(char *str, 
 			       char **mod, 
@@ -951,7 +951,7 @@ static int get_module(char **mbuf, char 
     while ((*tmp) == ' ') tmp++; /* eat space */
     start = tmp;
     while (1) {
-      if (isalnum((int)*tmp) || (*tmp == '_')) {
+      if (isalnum((unsigned char)*tmp) || (*tmp == '_')) {
 	tmp++;
 	continue;
       } else {
