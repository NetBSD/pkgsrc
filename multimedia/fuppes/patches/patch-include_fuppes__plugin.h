$NetBSD: patch-include_fuppes__plugin.h,v 1.1 2013/12/08 22:33:33 joerg Exp $

--- include/fuppes_plugin.h.orig	2013-12-08 20:21:31.000000000 +0000
+++ include/fuppes_plugin.h
@@ -57,9 +57,9 @@ static inline arg_list_t* arg_list_creat
 	arg_list_t* list = (arg_list_t*)malloc(sizeof(arg_list_t));
 	
 	list->key = (char*)malloc(sizeof(char));
-	list->key = '\0';
+	list->key[0] = '\0';
 	list->value = (char*)malloc(sizeof(char));
-	list->value = '\0';	
+	list->value[0] = '\0';
 
 	list->next = NULL;
 	
