$NetBSD: patch-codec-cfg.c,v 1.1 2025/11/15 12:43:17 ryoon Exp $

--- codec-cfg.c.orig	2025-10-08 03:42:53.829010043 +0000
+++ codec-cfg.c
@@ -406,7 +406,7 @@ static int validate_codec(codecs_t *c, i
     const char *name = codec_idx2str(c->name_idx);
     const char *tmp_name = name;
 
-    for (i = 0; i < strlen(tmp_name) && isalnum(tmp_name[i]); i++)
+    for (i = 0; i < strlen(tmp_name) && isalnum((unsigned char)(tmp_name[i])); i++)
         /* NOTHING */;
 
     if (i < strlen(tmp_name)) {
@@ -523,7 +523,7 @@ static int get_token(int min, int max)
         read_nextline = 0;
     }
     for (i = 0; i < max; i++) {
-        while (isspace(line[line_pos]))
+        while (isspace((unsigned char)(line[line_pos])))
             ++line_pos;
         if (line[line_pos] == '\0' || line[line_pos] == '#' ||
             line[line_pos] == ';') {
@@ -539,7 +539,7 @@ static int get_token(int min, int max)
             while (line[++line_pos] != c && line[line_pos])
                 /* NOTHING */;
         } else {
-            for (/* NOTHING */; !isspace(line[line_pos]) &&
+            for (/* NOTHING */; !isspace((unsigned char)(line[line_pos])) &&
                                   line[line_pos]; line_pos++)
                 /* NOTHING */;
         }
