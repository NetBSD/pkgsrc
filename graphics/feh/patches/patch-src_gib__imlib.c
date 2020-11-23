$NetBSD: patch-src_gib__imlib.c,v 1.1 2020/11/23 13:10:54 nia Exp $

ctype arguments must be unsigned char.

--- src/gib_imlib.c.orig	2020-08-29 06:50:28.000000000 +0000
+++ src/gib_imlib.c
@@ -514,7 +514,7 @@ gib_imlib_save_image(Imlib_Image im, cha
      p = strdup(tmp + 1);
      pp = p;
      while(*pp) {
-       *pp = tolower(*pp);
+       *pp = tolower((unsigned char)*pp);
        pp++;
      }
      imlib_image_set_format(p);
@@ -536,7 +536,7 @@ gib_imlib_save_image_with_error_return(I
         p = estrdup(tmp + 1);
         pp = p;
         while(*pp) {
-            *pp = tolower(*pp);
+            *pp = tolower((unsigned char)*pp);
             pp++;
         }
         imlib_image_set_format(p);
