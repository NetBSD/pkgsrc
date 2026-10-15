$NetBSD: patch-mflow.c,v 1.1 2026/10/15 19:44:23 ktnb Exp $

NetBSD 11 ctype fix.

--- mflow.c.orig	2026-10-15 19:37:27.104683588 +0000
+++ mflow.c
@@ -114,7 +114,7 @@ main(int argc, char *argv[])
 	}
 
 	char *cols = getenv("COLUMNS");
-	if (cols && isdigit(*cols)) {
+	if (cols && isdigit((unsigned char)*cols)) {
 		maxcolumn = atoi(cols);
 	} else {
 		struct winsize w;
@@ -129,7 +129,7 @@ main(int argc, char *argv[])
 	xpledge("stdio", "");
 
 	char *maxcols = getenv("MAXCOLUMNS");
-	if (maxcols && isdigit(*maxcols)) {
+	if (maxcols && isdigit((unsigned char)*maxcols)) {
 		int m = atoi(maxcols);
 		if (maxcolumn > m)
 			maxcolumn = m;
