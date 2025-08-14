$NetBSD: patch-tools_tiffdither.c,v 1.1 2025/08/14 10:02:21 wiz Exp $

Fix for CVE-2025-8176.
https://gitlab.com/libtiff/libtiff/-/merge_requests/727/diffs

--- tools/tiffdither.c.orig	2024-08-15 21:16:11.000000000 +0000
+++ tools/tiffdither.c
@@ -98,7 +98,7 @@ static int fsdither(TIFF *in, TIFF *out)
     nextptr = nextline;
     for (j = 0; j < imagewidth; ++j)
         *nextptr++ = *inptr++;
-    for (i = 1; i < imagelength; ++i)
+    for (i = 0; i < imagelength; ++i)
     {
         tmpptr = thisline;
         thisline = nextline;
@@ -146,7 +146,7 @@ static int fsdither(TIFF *in, TIFF *out)
                     nextptr[0] += v / 16;
             }
         }
-        if (TIFFWriteScanline(out, outline, i - 1, 0) < 0)
+        if (TIFFWriteScanline(out, outline, i, 0) < 0)
             goto skip_on_error;
     }
     goto exit_label;
