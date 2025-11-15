$NetBSD: patch-libvo_vo__fbdev.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- libvo/vo_fbdev.c.orig	2025-10-08 03:38:35.375096293 +0000
+++ libvo/vo_fbdev.c
@@ -128,7 +128,7 @@ static int get_token(int num)
         read_nextline = 0;
     }
     for (i = 0; i < num; i++) {
-        while (isspace(line[line_pos]))
+        while (isspace((unsigned char)(line[line_pos])))
             ++line_pos;
         if (line[line_pos] == '\0' || line[line_pos] == '#') {
             read_nextline = 1;
@@ -144,7 +144,7 @@ static int get_token(int num)
                 goto out_eol;
             line[line_pos] = ' ';
         } else {
-            for (/* NOTHING */; !isspace(line[line_pos]) &&
+            for (/* NOTHING */; !isspace((unsigned char)(line[line_pos])) &&
                                 line[line_pos]; line_pos++)
                 /* NOTHING */;
         }
