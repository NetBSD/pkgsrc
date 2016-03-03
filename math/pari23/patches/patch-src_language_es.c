$NetBSD: patch-src_language_es.c,v 1.1 2016/03/03 13:23:22 wiz Exp $

Remove fgets() indirection to fix build with USE_FORTIFY.

--- src/language/es.c.orig	2008-03-31 11:43:58.000000000 +0000
+++ src/language/es.c
@@ -215,7 +215,6 @@ gp_read_stream_buf(FILE *fi, Buffer *b)
   init_filtre(&F, b);
 
   IM.file = fi;
-  IM.fgets= &fgets;
   IM.getline= &file_input;
   IM.free = 0;
   return input_loop(&F,&IM);
@@ -309,7 +308,7 @@ file_input(char **s0, int junk, input_me
       *s0 = b->buf + used0;
     }
     s = b->buf + used;
-    if (! IM->fgets(s, left, IM->file))
+    if (! fgets(s, left, IM->file))
       return first? NULL: *s0; /* EOF */
 
     l = strlen(s); first = 0;
