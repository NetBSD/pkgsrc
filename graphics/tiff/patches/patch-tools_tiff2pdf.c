$NetBSD: patch-tools_tiff2pdf.c,v 1.5 2025/08/14 10:02:21 wiz Exp $

Fix for CVE-2024-13978.
https://gitlab.com/libtiff/libtiff/-/merge_requests/667

--- tools/tiff2pdf.c.orig	2024-08-15 21:16:14.000000000 +0000
+++ tools/tiff2pdf.c
@@ -1371,8 +1371,24 @@ void t2p_read_tiff_init(T2P *t2p, TIFF *
             t2p->pdf_xrefcount += (t2p->tiff_tiles[i].tiles_tilecount - 1) * 2;
             TIFFGetField(input, TIFFTAG_TILEWIDTH,
                          &(t2p->tiff_tiles[i].tiles_tilewidth));
+            if (t2p->tiff_tiles[i].tiles_tilewidth < 1)
+            {
+                TIFFError(TIFF2PDF_MODULE, "Invalid tile width (%d), %s",
+                          t2p->tiff_tiles[i].tiles_tilewidth,
+                          TIFFFileName(input));
+                t2p->t2p_error = T2P_ERR_ERROR;
+                return;
+            }
             TIFFGetField(input, TIFFTAG_TILELENGTH,
                          &(t2p->tiff_tiles[i].tiles_tilelength));
+            if (t2p->tiff_tiles[i].tiles_tilelength < 1)
+            {
+                TIFFError(TIFF2PDF_MODULE, "Invalid tile length (%d), %s",
+                          t2p->tiff_tiles[i].tiles_tilelength,
+                          TIFFFileName(input));
+                t2p->t2p_error = T2P_ERR_ERROR;
+                return;
+            }
             t2p->tiff_tiles[i].tiles_tiles = (T2P_TILE *)_TIFFmalloc(
                 TIFFSafeMultiply(tmsize_t, t2p->tiff_tiles[i].tiles_tilecount,
                                  sizeof(T2P_TILE)));
