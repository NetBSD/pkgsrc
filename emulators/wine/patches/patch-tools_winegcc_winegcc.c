$NetBSD: patch-tools_winegcc_winegcc.c,v 1.1 2021/06/01 05:05:54 adam Exp $

Move -lxxx args to the end of argument list, to fix linking on NetBSD.

--- tools/winegcc/winegcc.c.orig	2021-04-16 14:34:12.000000000 +0000
+++ tools/winegcc/winegcc.c
@@ -953,6 +953,7 @@ static void build(struct options* opts)
 {
     strarray *lib_dirs, *files;
     strarray *spec_args, *link_args;
+    strarray *link_libs = strarray_alloc();
     char *output_file, *output_path;
     const char *spec_o_name, *libgcc = NULL;
     const char *output_name, *spec_file, *lang;
@@ -1210,7 +1211,7 @@ static void build(struct options* opts)
 	switch(files->base[j][1])
 	{
 	    case 'l':
-		strarray_add(link_args, strmake("-l%s", name));
+		strarray_add(link_libs, strmake("-l%s", name));
 		break;
 	    case 's':
 	    case 'o':
@@ -1246,12 +1247,14 @@ static void build(struct options* opts)
 
     if (!opts->nostdlib && !is_pe)
     {
-	strarray_add(link_args, "-lm");
-	strarray_add(link_args, "-lc");
+	strarray_add(link_libs, "-lm");
+	strarray_add(link_libs, "-lc");
     }
 
-    if (libgcc) strarray_add(link_args, libgcc);
+    if (libgcc) strarray_add(link_libs, libgcc);
 
+    strarray_addall(link_args, link_libs);
+    strarray_free(link_libs);
     spawn(opts->prefix, link_args, 0);
     strarray_free (link_args);
 
