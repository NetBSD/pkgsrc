$NetBSD: patch-src_file__help.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/file_help.c.orig	2003-03-14 00:37:23.000000000 +0000
+++ src/file_help.c
@@ -42,7 +42,7 @@ static char *helpquote[]={
 
 /* *INDENT-ON* */
 
-static int export_help (int argc, char **argv, void *data)
+static uint64_t export_help (int argc, char **argv, void *data)
 {
 	Node *node = (Node *) data;
 	char *filename = argc==2?argv[1]:"";
@@ -55,7 +55,7 @@ static int export_help (int argc, char *
 	if (!file) {
 		cli_outfunf ("help export, unable to open \"%s\"", filename);
 
-		return (int) node;
+		return PTR_TO_UINT64(node);
 	}
 	startlevel = nodes_left (node);
 
@@ -86,10 +86,10 @@ static int export_help (int argc, char *
 	fclose (file);
 
 	cli_outfunf ("help export, wrote data to \"%s\"", filename);
-	return (int) node;
+	return PTR_TO_UINT64(node);
 }
 
-static int import_help (int argc, char **argv, void *data)
+static uint64_t import_help (int argc, char **argv, void *data)
 {
 	Node *node = (Node *) data;
 	import_state_t ist;
@@ -100,7 +100,7 @@ static int import_help (int argc, char *
 	if (node_getflag (node, F_temp))
 		node = node_remove (node);
 
-	return (int) (node);
+	return PTR_TO_UINT64(node);
 }
 
 /*
