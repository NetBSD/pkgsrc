$NetBSD: patch-bdf.c,v 1.1 2023/09/09 14:56:28 vins Exp $

Prevent insecure fprintf() usage.

--- bdf.c.orig	2004-02-23 14:08:07.000000000 +0000
+++ bdf.c
@@ -3058,14 +3058,14 @@ void *data;
         bpr = ((c->bbx.width * font->bpp) + 7) >> 3;
         for (j = 0; bpr != 0 && j < c->bytes; j++) {
             if (j && j % bpr == 0)
-              fprintf(out, eol);
+              fprintf(out, "%s", eol);
             fprintf(out, "%02X", c->bitmap[j]);
         }
         /*
          * Handle empty bitmaps like this.
          */
         if (c->bbx.height > 0)
-          fprintf(out, eol);
+          fprintf(out, "%s", eol);
         fprintf(out, "ENDCHAR%s", eol);
 
         /*
@@ -3130,14 +3130,14 @@ void *data;
         bpr = ((c->bbx.width * font->bpp) + 7) >> 3;
         for (j = 0; bpr != 0 && j < c->bytes; j++) {
             if (j && j % bpr == 0)
-              fprintf(out, eol);
+              fprintf(out, "%s", eol);
             fprintf(out, "%02X", c->bitmap[j]);
         }
         /*
          * Handle empty bitmaps like this.
          */
         if (c->bbx.height > 0)
-          fprintf(out, eol);
+          fprintf(out, "%s", eol);
         fprintf(out, "ENDCHAR%s", eol);
 
         /*
