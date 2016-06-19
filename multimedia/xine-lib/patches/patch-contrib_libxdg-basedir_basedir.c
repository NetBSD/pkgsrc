$NetBSD: patch-contrib_libxdg-basedir_basedir.c,v 1.1 2016/06/19 23:05:17 joerg Exp $

Fix empty body problems.

--- contrib/libxdg-basedir/basedir.c.orig	2016-06-19 19:28:26.879811053 +0000
+++ contrib/libxdg-basedir/basedir.c
@@ -143,14 +143,14 @@ static void xdgFreeStringList(char** lis
 /** Free all data in the cache and set pointers to null. */
 static void xdgFreeData(xdgCachedData *cache)
 {
-	if (cache->dataHome);
+	if (cache->dataHome)
 	{
 		/* the first element of the directory lists is usually the home directory */
 		if (cache->searchableDataDirectories[0] != cache->dataHome)
 			free(cache->dataHome);
 		cache->dataHome = 0;
 	}
-	if (cache->configHome);
+	if (cache->configHome)
 	{
 		if (cache->searchableConfigDirectories[0] != cache->configHome)
 			free(cache->configHome);
@@ -280,9 +280,9 @@ static char** xdgGetPathListEnv(const ch
 	else
 	{
 		if (!strings) return NULL;
-		for (size = 0; strings[size]; ++size) ; ++size;
-		if (!(itemlist = (char**)malloc(sizeof(char*)*size))) return NULL;
-		xdgZeroMemory(itemlist, sizeof(char*)*(size));
+		for (size = 0; strings[size++];)
+			;
+		if (!(itemlist = calloc(sizeof(char*), size))) return NULL;
 
 		/* Copy defaults into itemlist. */
 		/* Why all this funky stuff? So the result can be handled uniformly by xdgFreeStringList. */
