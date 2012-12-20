$NetBSD: patch-graphic.c,v 1.1 2012/12/20 21:49:07 joerg Exp $

--- graphic.c.orig	2012-12-20 12:19:11.000000000 +0000
+++ graphic.c
@@ -748,7 +748,7 @@ grafinit (void)
 			    &visualinfo))
     {
       error (ERROR, "Could not get any TrueColor visual");
-      return;
+      return FALSE;
     }
 
   /* convert color masks in more convenient values */
@@ -790,7 +790,7 @@ grafinit (void)
       sprintf (string, "Could not find foreground color '%s'\n",
 	       background);
       error (ERROR, string);
-      return;
+      return FALSE;
     }
   forepixel =
       rgb_to_pixel (best_match.red >> 8, best_match.green >> 8,
@@ -806,7 +806,7 @@ grafinit (void)
       sprintf (string, "Could not find background color '%s'\n",
 	       background);
       error (ERROR, string);
-      return;
+      return FALSE;
     }
   backpixel =
       rgb_to_pixel (best_match.red >> 8, best_match.green >> 8,
