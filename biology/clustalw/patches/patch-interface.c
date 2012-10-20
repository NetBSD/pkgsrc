$NetBSD: patch-interface.c,v 1.1 2012/10/20 22:02:07 joerg Exp $

--- interface.c.orig	2012-10-20 14:27:11.000000000 +0000
+++ interface.c
@@ -210,7 +210,7 @@ static sint check_param(char **args,char
 		Boolean 	name1 = FALSE;
 		sint ajb;
 
-	if(args[0]==NULL) return;
+	if(args[0]==NULL) return -1;
 
 
 
