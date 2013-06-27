$NetBSD: patch-src_text.c,v 1.1 2013/06/27 15:49:43 joerg Exp $

--- src/text.c.orig	2013-06-26 22:51:11.000000000 +0000
+++ src/text.c
@@ -333,7 +333,7 @@ begin_font (const char *name, int size, 
   saved_total_height = total_height;
 
   font = xmalloc (sizeof (struct font));
-  memset (font, 0, sizeof font);
+  memset (font, 0, sizeof *font);
   font->next = fonts;
   fonts = font;
 
