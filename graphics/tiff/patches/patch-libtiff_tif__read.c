$NetBSD: patch-libtiff_tif__read.c,v 1.3 2025/08/14 10:02:21 wiz Exp $

Fix for CVE-2024-13978.
https://gitlab.com/libtiff/libtiff/-/merge_requests/667

--- libtiff/tif_read.c.orig	2024-08-15 21:16:11.000000000 +0000
+++ libtiff/tif_read.c
@@ -466,7 +466,9 @@ int TIFFReadScanline(TIFF *tif, void *bu
     }
     else
     {
-        memset(buf, 0, (size_t)tif->tif_scanlinesize);
+        /* See TIFFReadEncodedStrip comment regarding TIFFTAG_FAXFILLFUNC. */
+        if (buf)
+            memset(buf, 0, (size_t)tif->tif_scanlinesize);
     }
     return (e > 0 ? 1 : -1);
 }
@@ -554,7 +556,10 @@ tmsize_t TIFFReadEncodedStrip(TIFF *tif,
         stripsize = size;
     if (!TIFFFillStrip(tif, strip))
     {
-        memset(buf, 0, (size_t)stripsize);
+        /* The output buf may be NULL, in particular if TIFFTAG_FAXFILLFUNC
+           is being used. Thus, memset must be conditional on buf not NULL. */
+        if (buf)
+            memset(buf, 0, (size_t)stripsize);
         return ((tmsize_t)(-1));
     }
     if ((*tif->tif_decodestrip)(tif, buf, stripsize, plane) <= 0)
@@ -976,7 +981,9 @@ tmsize_t TIFFReadEncodedTile(TIFF *tif, 
         size = tilesize;
     if (!TIFFFillTile(tif, tile))
     {
-        memset(buf, 0, (size_t)size);
+        /* See TIFFReadEncodedStrip comment regarding TIFFTAG_FAXFILLFUNC. */
+        if (buf)
+            memset(buf, 0, (size_t)size);
         return ((tmsize_t)(-1));
     }
     else if ((*tif->tif_decodetile)(tif, (uint8_t *)buf, size,
@@ -1569,7 +1576,9 @@ int TIFFReadFromUserBuffer(TIFF *tif, ui
         if (!TIFFStartTile(tif, strile))
         {
             ret = 0;
-            memset(outbuf, 0, (size_t)outsize);
+            /* See related TIFFReadEncodedStrip comment. */
+            if (outbuf)
+                memset(outbuf, 0, (size_t)outsize);
         }
         else if (!(*tif->tif_decodetile)(
                      tif, (uint8_t *)outbuf, outsize,
@@ -1596,7 +1605,9 @@ int TIFFReadFromUserBuffer(TIFF *tif, ui
             if (!TIFFStartStrip(tif, strile))
             {
                 ret = 0;
-                memset(outbuf, 0, (size_t)outsize);
+                /* See related TIFFReadEncodedStrip comment. */
+                if (outbuf)
+                    memset(outbuf, 0, (size_t)outsize);
             }
             else if (!(*tif->tif_decodestrip)(
                          tif, (uint8_t *)outbuf, outsize,
