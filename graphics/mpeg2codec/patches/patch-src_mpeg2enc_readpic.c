$NetBSD: patch-src_mpeg2enc_readpic.c,v 1.1 2026/03/18 14:38:19 nia Exp $

Fix implicit function declarations.

--- src/mpeg2enc/readpic.c.orig	2026-03-18 14:14:36.440737855 +0000
+++ src/mpeg2enc/readpic.c
@@ -40,6 +40,7 @@ static void border_extend _ANSI_ARGS_((u
   int w2, int h2));
 static void conv444to422 _ANSI_ARGS_((unsigned char *src, unsigned char *dst));
 static void conv422to420 _ANSI_ARGS_((unsigned char *src, unsigned char *dst));
+int pbm_getint(FILE *);
 
 void readframe(fname,frame)
 char *fname;
