$NetBSD: patch-MagickCore_delegate.c,v 1.1 2018/02/18 23:45:07 rillig Exp $

See https://github.com/ImageMagick/ImageMagick/pull/988

--- MagickCore/delegate.c.orig	2018-01-06 14:18:42.000000000 +0000
+++ MagickCore/delegate.c
@@ -931,7 +931,7 @@ RestoreMSCWarning
   extent=MagickPathExtent;  /* allocated space in string */
   number=MagickFalse;  /* is last char a number? */
   for (q=interpret_text; *p!='\0';
-    number=isdigit(*p) ? MagickTrue : MagickFalse,p++)
+    number=isdigit((int) ((unsigned char) *p)) ? MagickTrue : MagickFalse,p++)
   {
     /*
       Interpret escape characters (e.g. Filename: %M).
