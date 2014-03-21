$NetBSD: patch-src_plugins_dirtree.c,v 1.1 2014/03/21 14:19:31 jperkin Exp $

Portable directory tests.

--- src/plugins/dirtree.c.orig	2013-02-28 01:03:34.000000000 +0000
+++ src/plugins/dirtree.c
@@ -232,6 +232,9 @@ static gboolean _dirtree_refresh_folder(
 	gboolean ret = FALSE;
 	DIR * dir;
 	struct dirent * de;
+#ifdef __sun
+	struct stat st;
+#endif
 	GtkTreeModel * model = GTK_TREE_MODEL(dirtree->store);
 	GtkTreeIter iter;
 	GtkTreePath * s;
@@ -256,14 +259,22 @@ static gboolean _dirtree_refresh_folder(
 		path = "";
 	while((de = readdir(dir)) != NULL)
 	{
+#ifdef __sun
+		stat(de->d_name, &st);
+#endif
 		/* skip hidden folders except if we traverse it */
 		if(basename != NULL && strcmp(de->d_name, basename) == 0)
 			ret = TRUE;
 		else if(de->d_name[0] == '.')
 			continue;
+#ifdef __sun
+		else if (!(st.st_mode & S_IFDIR))
+			continue;
+#else
 		/* XXX d_type is not portable */
 		else if(de->d_type != DT_DIR)
 			continue;
+#endif
 		q = string_new_append(path, "/", de->d_name, NULL);
 		/* FIXME check if the node already exists */
 		r = (q != NULL) ? g_filename_display_basename(q) : NULL;
