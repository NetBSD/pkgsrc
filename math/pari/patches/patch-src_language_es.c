$NetBSD: patch-src_language_es.c,v 1.2 2016/03/03 13:28:22 wiz Exp $

--- src/language/es.c.orig	2015-09-26 23:11:11.000000000 +0000
+++ src/language/es.c
@@ -243,7 +243,6 @@ gp_read_stream_buf(FILE *fi, Buffer *b)
   init_filtre(&F, b);
 
   IM.file = fi;
-  IM.fgets= &fgets;
   IM.getline= &file_input;
   IM.free = 0;
   return input_loop(&F,&IM);
@@ -337,7 +336,7 @@ file_getline(Buffer *b, char **s0, input
     /* # of chars read by fgets is an int; be careful */
     read = minuu(left, MAX);
     s = b->buf + used;
-    if (! IM->fgets(s, (int)read, IM->file)) return **s0? *s0: NULL; /* EOF */
+    if (! fgets(s, (int)read, IM->file)) return **s0? *s0: NULL; /* EOF */
 
     l = strlen(s);
     if (l+1 < read || s[l-1] == '\n') return *s0; /* \n */
