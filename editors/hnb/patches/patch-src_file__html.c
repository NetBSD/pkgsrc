$NetBSD: patch-src_file__html.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/file_html.c.orig	2003-03-14 00:36:52.000000000 +0000
+++ src/file_html.c
@@ -52,7 +52,7 @@ static char *htmlquote[]={
 /* *INDENT-ON* */
 
 
-static int export_html (int argc, char **argv, void *data)
+static uint64_t export_html (int argc, char **argv, void *data)
 {
 	Node *node = (Node *) data;
 	char *filename = argc==2?argv[1]:"";
@@ -67,7 +67,7 @@ static int export_html (int argc, char *
 		file = fopen (filename, "w");
 	if (!file) {
 		cli_outfunf ("html export, unable to open \"%s\"", filename);
-		return (int) node;
+		return PTR_TO_UINT64(node);
 	}
 
 	startlevel = nodes_left (node);
@@ -130,7 +130,7 @@ static int export_html (int argc, char *
 		fclose (file);
 
 	cli_outfunf ("html export, saved output in \"%s\"", filename);
-	return (int) node;
+	return  PTR_TO_UINT64(node);
 }
 
 static void htmlcss_export_nodes (FILE * file, Node *node, int level)
@@ -162,7 +162,7 @@ static void htmlcss_export_nodes (FILE *
 }
 
 
-static int export_htmlcss (int argc, char **argv, void *data)
+static uint64_t export_htmlcss (int argc, char **argv, void *data)
 {
 	Node *node = (Node *) data;
 	char *filename = argc==2?argv[1]:"";
@@ -174,7 +174,7 @@ static int export_htmlcss (int argc, cha
 		file = fopen (filename, "w");
 	if (!file) {
 		cli_outfunf ("html export, unable to open \"%s\"", filename);
-		return (int) node;
+		return PTR_TO_UINT64(node);
 	}
 
 	fprintf (file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\
@@ -224,7 +224,7 @@ div.level2 {\n\
 		fclose (file);
 
 	cli_outfunf ("html css export, saved output in \"%s\"", filename);
-	return (int) node;
+	return PTR_TO_UINT64(node);
 }
 
 /*
