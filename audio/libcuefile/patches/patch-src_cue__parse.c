$NetBSD: patch-src_cue__parse.c,v 1.1 2025/05/01 16:20:24 tnn Exp $

add missing prototype

--- src/cue_parse.c.orig	2025-05-01 16:17:34.567058974 +0000
+++ src/cue_parse.c
@@ -1513,6 +1513,7 @@ void yyerror (char *s)
 	fprintf(stderr, "%d: %s\n", cue_lineno, s);
 }
 
+void cue_delete_buffer();
 Cd *cue_parse (FILE *fp)
 {
 	cue_yyin = fp;
