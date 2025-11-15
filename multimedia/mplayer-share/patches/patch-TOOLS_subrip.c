$NetBSD: patch-TOOLS_subrip.c,v 1.1 2025/11/15 12:43:17 ryoon Exp $

--- TOOLS/subrip.c.orig	2025-10-08 03:39:22.607482214 +0000
+++ TOOLS/subrip.c
@@ -129,7 +129,7 @@ process_gocr_output(const char *const fn
     bol = 1;
     while ((c = getc(file)) != EOF) {
 	if (bol) {
-	    if (!isspace(c)) {
+	    if (!isspace((unsigned char)c)) {
 		putc(c, fsub);
 		bol=0;
 	    }
