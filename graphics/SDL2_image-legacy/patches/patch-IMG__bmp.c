$NetBSD: patch-IMG__bmp.c,v 1.1 2024/05/06 18:05:32 nia Exp $

Fix various security issues,
CVE-2017-14441
CVE-2017-14442

Taken from Ubuntu Linux.

--- IMG_bmp.c.orig	2016-01-03 05:52:28.000000000 +0000
+++ IMG_bmp.c
@@ -738,6 +738,14 @@ LoadICOCUR_RW(SDL_RWops * src, int type,
         goto done;
     }
 
+    /* sanity check image size, so we don't overflow integers, etc. */
+    if ((biWidth < 0) || (biWidth > 0xFFFFFF) ||
+        (biHeight < 0) || (biHeight > 0xFFFFFF)) {
+        IMG_SetError("Unsupported or invalid ICO dimensions");
+        was_error = SDL_TRUE;
+        goto done;
+    }
+
     /* Create a RGBA surface */
     biHeight = biHeight >> 1;
     //printf("%d x %d\n", biWidth, biHeight);
@@ -755,6 +763,11 @@ LoadICOCUR_RW(SDL_RWops * src, int type,
         if (biClrUsed == 0) {
             biClrUsed = 1 << biBitCount;
         }
+        if (biClrUsed > SDL_arraysize(palette)) {
+            IMG_SetError("Unsupported or incorrect biClrUsed field");
+            was_error = SDL_TRUE;
+            goto done;
+        }
         for (i = 0; i < (int) biClrUsed; ++i) {
             SDL_RWread(src, &palette[i], 4, 1);
         }
