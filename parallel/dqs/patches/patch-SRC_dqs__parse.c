$NetBSD: patch-SRC_dqs__parse.c,v 1.1 2013/03/28 21:37:23 joerg Exp $

--- SRC/dqs_parse.c.orig	2000-10-01 23:57:33.000000000 +0000
+++ SRC/dqs_parse.c
@@ -2837,9 +2837,7 @@ void dqs_parse_user_list(head,user_str)
 
 
 /***************************************************************************/
-void *dqs_get_env_list(head,envp)
-     dqs_list_type **head;
-     char **envp;
+void dqs_get_env_list(dqs_list_type **head, char **envp)
      
      /*
        str0 = env_name
