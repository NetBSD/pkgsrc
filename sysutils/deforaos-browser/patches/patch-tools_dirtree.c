$NetBSD: patch-tools_dirtree.c,v 1.1 2014/03/21 14:19:31 jperkin Exp $

Portable directory tests.

--- tools/dirtree.c.orig	2013-01-02 03:37:28.000000000 +0000
+++ tools/dirtree.c
@@ -22,6 +22,9 @@
 #include <string.h>
 #include <libgen.h>
 #include <gtk/gtk.h>
+#ifdef __sun
+#include <sys/stat.h>
+#endif
 
 
 /* dirtree */
@@ -111,6 +114,9 @@ static int _dirtree_add(GtkTreeStore * s
 	char * str;
 	DIR * dir;
 	struct dirent * de;
+#ifdef __sun
+	struct stat st;
+#endif
 	char * q;
 	GtkTreeIter iter2;
 
@@ -128,9 +134,16 @@ static int _dirtree_add(GtkTreeStore * s
 	snprintf(str, len + 1, "%s/", p);
 	while((de = readdir(dir)) != NULL)
 	{
+#ifdef __sun
+		stat(de->d_name, &st);
+		if(!(st.st_mode & S_IFDIR)
+				|| strcmp(".", de->d_name) == 0
+				|| strcmp("..", de->d_name) == 0)
+#else
 		if(!(de->d_type & DT_DIR)
 				|| strcmp(".", de->d_name) == 0
 				|| strcmp("..", de->d_name) == 0)
+#endif
 			continue;
 		if((q = realloc(str, len + strlen(de->d_name) + 1)) == NULL)
 			continue;
