$NetBSD: patch-tools_tiffmedian.c,v 1.1 2025/08/14 10:02:21 wiz Exp $

Fix for CVE-2025-8176.
https://gitlab.com/libtiff/libtiff/-/merge_requests/727/diffs

--- tools/tiffmedian.c.orig	2024-08-15 21:16:11.000000000 +0000
+++ tools/tiffmedian.c
@@ -414,7 +414,10 @@ static void get_histogram(TIFF *in, Colo
     for (i = 0; i < imagelength; i++)
     {
         if (TIFFReadScanline(in, inputline, i, 0) <= 0)
-            break;
+        {
+            fprintf(stderr, "Error reading scanline\n");
+            exit(EXIT_FAILURE);
+        }
         inptr = inputline;
         for (j = imagewidth; j-- > 0;)
         {
@@ -917,7 +920,7 @@ static void quant_fsdither(TIFF *in, TIF
     outline = (unsigned char *)_TIFFmalloc(TIFFScanlineSize(out));
 
     GetInputLine(in, 0, goto bad); /* get first line */
-    for (i = 1; i <= imagelength; ++i)
+    for (i = 0; i < imagelength; ++i)
     {
         SWAP(short *, thisline, nextline);
         lastline = (i >= imax);
@@ -997,7 +1000,7 @@ static void quant_fsdither(TIFF *in, TIF
                 nextptr += 3;
             }
         }
-        if (TIFFWriteScanline(out, outline, i - 1, 0) < 0)
+        if (TIFFWriteScanline(out, outline, i, 0) < 0)
             break;
     }
 bad:
