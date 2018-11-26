$NetBSD: patch-src_file__xml.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/file_xml.c.orig	2003-03-14 00:36:08.000000000 +0000
+++ src/file_xml.c
@@ -147,7 +147,7 @@ static void xml_export_nodes (FILE * fil
 	}
 }
 
-static int export_xml (int argc, char **argv, void *data)
+static uint64_t export_xml (int argc, char **argv, void *data)
 {
 	Node *node = (Node *) data;
 	char *filename = argc==2?argv[1]:"";
@@ -159,7 +159,7 @@ static int export_xml (int argc, char **
 		file = fopen (filename, "w");
 	if (!file) {
 		cli_outfunf ("xml export, unable to open \"%s\"", filename);
-		return (int) node;
+		return PTR_TO_UINT64(node);
 	}
 
 	xml_export_nodes (file, node, 0);
@@ -170,7 +170,7 @@ static int export_xml (int argc, char **
 	cli_outfunf ("xml export, wrote data to \"%s\"", filename);
 
 
-	return (int) node;
+	return PTR_TO_UINT64(node);
 }
 
 /* joins up tags with data if there is data as the first child
@@ -202,7 +202,7 @@ static Node *xml_cuddle_nodes (Node *nod
 }
 
 
-static int import_xml (int argc, char **argv, void *data)
+static uint64_t import_xml (int argc, char **argv, void *data)
 {
 	Node *node = (Node *) data;
 	char *filename = argc==2?argv[1]:"";
@@ -221,7 +221,7 @@ static int import_xml (int argc, char **
 	file = fopen (filename, "r");
 	if (!file) {
 		cli_outfunf ("xml import, unable to open \"%s\"", filename);
-		return (int) node;
+		return PTR_TO_UINT64(node);
 	}
 	s = xml_tok_init (file);
 	init_import (&ist, node);
@@ -231,7 +231,7 @@ static int import_xml (int argc, char **
 			cli_outfunf ("xml import error, parsing og '%s', line:%i %s", filename,
 						 s->line_no,rdata);
 			fclose (file);
-			return (int) node;
+			return PTR_TO_UINT64(node);
 		}
 
 		switch (type) {
@@ -328,7 +328,7 @@ static int import_xml (int argc, char **
 
 	cli_outfunf ("xml import - imported \"%s\" %i lines", filename, s->line_no);
 	xml_tok_cleanup (s);
-	return (int) node;
+	return PTR_TO_UINT64(node);
 }
 
 /*
