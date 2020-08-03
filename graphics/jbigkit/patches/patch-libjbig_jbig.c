$NetBSD: patch-libjbig_jbig.c,v 1.1 2020/08/03 21:34:06 wiz Exp $

Fix CVE-2019-9937 using upstream commit bc3293299bc4981e83b7f37f3615a6b9b27b6837

--- libjbig/jbig.c.orig	2014-03-27 18:47:15.000000000 +0000
+++ libjbig/jbig.c
@@ -2051,6 +2051,7 @@ void jbg_dec_init(struct jbg_dec_state *
   s->xmax = 4294967295UL;
   s->ymax = 4294967295UL;
   s->dmax = 256;
+  s->maxmem = 2000000000;  /* no final image larger than 2 GB by default */
   s->s = NULL;
 
   return;
@@ -2640,6 +2641,10 @@ int jbg_dec_in(struct jbg_dec_state *s, 
       return JBG_EIMPL | 5;
     s->options = s->buffer[19];
 
+    /* will the final image require more bytes than permitted by s->maxmem? */
+    if (s->maxmem / s->planes / s->yd / jbg_ceil_half(s->xd, 3) == 0)
+      return JBG_ENOMEM;   /* increase s->maxmem if needed */
+
     /* calculate number of stripes that will be required */
     s->stripes = jbg_stripes(s->l0, s->yd, s->d);
     
