$NetBSD: patch-contrib_libxdg-basedir_basedir.c,v 1.2 2018/11/13 11:10:41 markd Exp $

Fix empty body problems.

--- contrib/libxdg-basedir/basedir.c.orig	2018-01-11 12:49:47.000000000 +0000
+++ contrib/libxdg-basedir/basedir.c
@@ -282,10 +282,9 @@ static char** xdgGetPathListEnv(const ch
 	else
 	{
 		if (!strings) return NULL;
-		for (size = 0; strings[size]; ++size) ;
-                ++size;
-		if (!(itemlist = (char**)malloc(sizeof(char*)*size))) return NULL;
-		xdgZeroMemory(itemlist, sizeof(char*)*(size));
+		for (size = 0; strings[size++];)
+			;
+		if (!(itemlist = calloc(sizeof(char*), size))) return NULL;
 
 		/* Copy defaults into itemlist. */
 		/* Why all this funky stuff? So the result can be handled uniformly by xdgFreeStringList. */
