$NetBSD: patch-src_ui__draw.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/ui_draw.c.orig	2003-03-10 00:44:29.000000000 +0000
+++ src/ui_draw.c
@@ -525,7 +525,7 @@ static struct {
 
 /* FIXME: make backup?,.. and make sure data is present,.., make possiblity to write back? */
 
-int display_format_cmd (int argc, char **argv, void *data)
+uint64_t display_format_cmd (int argc, char **argv, void *data)
 {
 	char *p = argv[1];
 	int width;
@@ -533,7 +533,7 @@ int display_format_cmd (int argc, char *
 	int col_no = 0;
 
 	if(argc<2){
-		return (int)data;
+		return PTR_TO_UINT64(data);
 	}
 
 	do {
@@ -618,7 +618,7 @@ int display_format_cmd (int argc, char *
 
 	col_def[col_no].type = col_terminate;
 
-	return (int) data;
+	return PTR_TO_UINT64(data);
 }
 
 
