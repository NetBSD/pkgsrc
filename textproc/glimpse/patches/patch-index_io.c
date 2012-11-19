$NetBSD: patch-index_io.c,v 1.1 2012/11/19 03:05:04 joerg Exp $

--- index/io.c.orig	2012-11-18 22:53:18.000000000 +0000
+++ index/io.c
@@ -365,7 +365,7 @@ static int copy_file(const char *source,
 
 
 
-
+void
 read_filters(index_dir, dofilter)
 char	*index_dir;
 int	dofilter;
@@ -1460,6 +1460,7 @@ get_filename_index(name)
 	return e->index;
 }
 
+void
 insert_filename(name, name_index)
 	char	*name;
 	int	name_index;
@@ -1512,6 +1513,7 @@ insert_filename(name, name_index)
 	(*pe)->index = name_index;
 }
 
+void
 change_filename(name, len, index, newname)
 	char	*name;
 	int	len;
@@ -1534,6 +1536,7 @@ change_filename(name, len, index, newnam
 	return;
 }
 
+void
 delete_filename(name, name_index)
 	char	*name;
 	int	name_index;
@@ -1577,6 +1580,7 @@ delete_filename(name, name_index)
 	return;
 }
 
+void
 init_filename_hashtable()
 {
 	int	i;
@@ -1584,6 +1588,8 @@ init_filename_hashtable()
 }
 
 int	built_filename_hashtable = 0;
+
+void
 build_filename_hashtable(names, num)
 	char	**names[];
 	int	num;
@@ -1595,6 +1601,7 @@ build_filename_hashtable(names, num)
 	built_filename_hashtable = 1;
 }
 
+void
 destroy_filename_hashtable()
 {
 	int	i;
