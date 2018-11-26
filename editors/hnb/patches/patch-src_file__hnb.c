$NetBSD: patch-src_file__hnb.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t.
2. Replaced pointer to int type cast with a macro to help
   convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/file_hnb.c.orig	2003-03-14 00:37:13.000000000 +0000
+++ src/file_hnb.c
@@ -105,7 +105,7 @@ static void hnb_export_nodes (FILE * fil
 	}
 }
 
-static int export_hnb (int argc, char **argv, void *data)
+static uint64_t export_hnb (int argc, char **argv, void *data)
 {
 	Node *node = (Node *) data;
 	char *filename = argc>=2?argv[1]:"";
@@ -118,7 +118,7 @@ static int export_hnb (int argc, char **
 
 	if (!file) {
 		cli_outfunf ("hnb export, unable to open \"%s\"", filename);
-		return (int) node;
+		return PTR_TO_UINT64(node);
 	}
 
 	fprintf (file, "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?><?pos=\"%s\"?>\n\
@@ -143,11 +143,11 @@ static int export_hnb (int argc, char **
 
 	cli_outfunf ("hnb export, wrote data to \"%s\"", filename);
 
-	return (int) node;
+	return PTR_TO_UINT64(node);
 }
 
 
-static int import_hnb (int argc, char **argv, void *data)
+static uint64_t import_hnb (int argc, char **argv, void *data)
 {
 	Node *node = (Node *) data;
 	char *filename = argc==2?argv[1]:"";
@@ -170,7 +170,7 @@ static int import_hnb (int argc, char **
 	file = fopen (filename, "r");
 	if (!file) {
 		cli_outfunf ("hnb import, unable to open \"%s\"", filename);
-		return (int) node;
+		return PTR_TO_UINT64(node);
 	}
 	s = xml_tok_init (file);
 	init_import (&ist, node);
@@ -180,7 +180,7 @@ static int import_hnb (int argc, char **
 			cli_outfunf ("hnb import error, parsing og '%s' line:%i, %s", filename,
 						 s->line_no, rdata);
 			fclose (file);
-			return (int) node;
+			return PTR_TO_UINT64(node);
 		}
 		if (in_tree) {
 			if (type == t_tag && !strcmp (rdata, "node")) {
@@ -263,7 +263,7 @@ static int import_hnb (int argc, char **
 
 	xml_tok_cleanup (s);
 
-	return (int) node;
+	return PTR_TO_UINT64(node);
 }
 
 /*
