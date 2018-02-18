$NetBSD: patch-MagickCore_property.c,v 1.1 2018/02/18 23:45:07 rillig Exp $

See https://github.com/ImageMagick/ImageMagick/pull/989

--- MagickCore/property.c.orig	2018-01-06 14:18:42.000000000 +0000
+++ MagickCore/property.c
@@ -3375,7 +3375,7 @@ RestoreMSCWarning
   interpret_text=AcquireString(embed_text); /* new string with extra space */
   extent=MagickPathExtent;                     /* allocated space in string */
   number=MagickFalse;                       /* is last char a number? */
-  for (q=interpret_text; *p!='\0'; number=isdigit(*p) ? MagickTrue : MagickFalse,p++)
+  for (q=interpret_text; *p!='\0'; number=isdigit((int) ((unsigned char) *p)) ? MagickTrue : MagickFalse,p++)
   {
     /*
       Look for the various escapes, (and handle other specials)
