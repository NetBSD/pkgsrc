$NetBSD: patch-src_racket_src_string.c,v 1.1 2012/09/15 13:33:59 marino Exp $

Part of DragonFly fix from Chris Turner and Jelle Hermsen.
toupper/tolower return int, patch recasts to char

--- src/racket/src/string.c.orig	2012-08-06 22:51:47.000000000 +0000
+++ src/racket/src/string.c
@@ -2909,10 +2909,9 @@ static char *locale_recase(int to_up,
 
   /* Re-case chars in "out" */
   for (i = 0; i < iilen; i++) {
-    if (to_up)
-      out[od + i] = toupper(out[od + i]);
-    else
-      out[od + i] = tolower(out[od + i]);
+    char t;
+    t = (to_up) ? toupper(out[od+i]) : tolower(out[od+i]);
+    out[od+i] = t;
   }
 
   return out;
