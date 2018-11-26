$NetBSD: patch-src_file__ps.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/file_ps.c.orig	2003-03-14 00:36:23.000000000 +0000
+++ src/file_ps.c
@@ -60,7 +60,7 @@ static void ps_export_node (FILE * file,
 	free(quoted);
 }
 
-static int export_ps (int argc, char **argv, void *data)
+static uint64_t export_ps (int argc, char **argv, void *data)
 {
 	Node *node = (Node *) data;
 	char *filename = argc==2?argv[1]:"";
@@ -75,7 +75,7 @@ static int export_ps (int argc, char **a
 		file = fopen (filename, "w");
 	if (!file) {
 		cli_outfunf ("postscript export, unable to open \"%s\"", filename);
-		return (int) node;
+		return PTR_TO_UINT64(node);
 	}
 	startlevel = nodes_left (node);
 
@@ -225,7 +225,7 @@ close\n\
 	cli_outfunf ("postscript export, saved output to \"%s\"", filename);
 	if (file != stdout)
 		fclose (file);
-	return (int) node;
+	return PTR_TO_UINT64(node);
 }
 
 /*
