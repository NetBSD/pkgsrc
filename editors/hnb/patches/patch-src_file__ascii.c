$NetBSD: patch-src_file__ascii.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/file_ascii.c.orig	2003-03-14 00:37:39.000000000 +0000
+++ src/file_ascii.c
@@ -34,7 +34,7 @@
 
 static int ascii_margin = -1;
 
-static int import_ascii (int argc, char **argv, void *data)
+static uint64_t import_ascii (int argc, char **argv, void *data)
 {
 	Node *node = (Node *) data;
 	char *filename = argc==2?argv[1]:"";
@@ -46,7 +46,7 @@
 	file = fopen (filename, "r");
 	if (file == NULL) {
 		cli_outfunf ("ascii import, unable to open \"%s\"", filename);
-		return (int) (node);
+		return PTR_TO_UINT64 (node);
 	}
 
 	init_import (&ist, node);
@@ -73,7 +73,7 @@
 	cli_outfunf ("ascii import, imported \"%s\"", filename);
 
 
-	return (int) (node);
+	return PTR_TO_UINT64 (node);
 }
 
 static void ascii_export_node (FILE * file, int level, int flags, char *data)
@@ -95,7 +95,7 @@
 	}
 }
 
-static int export_ascii (int argc, char **argv, void *data)
+static uint64_t export_ascii (int argc, char **argv, void *data)
 {
 	Node *node = (Node *) data;
 	char *filename = argc==2?argv[1]:"";
@@ -110,7 +110,7 @@
 		file = fopen (filename, "w");
 	if (!file) {
 		cli_outfunf ("ascii export, unable to open \"%s\"", filename);
-		return (int) node;
+		return PTR_TO_UINT64(node);
 	}
 	startlevel = nodes_left (node);
 
@@ -130,7 +130,7 @@
 
 	cli_outfunf ("ascii export, wrote output to \"%s\"", filename);
 
-	return (int) node;
+	return PTR_TO_UINT64(node);
 }
 
 
