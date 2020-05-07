$NetBSD: patch-zathura-pdf-mupdf_index.c,v 1.1 2020/05/07 20:45:28 leot Exp $

Backport upstream commit c7f341addb76d5e6fd8c24c666d8fe97c451a4cb to
update to mupdf 1.17.

--- zathura-pdf-mupdf/index.c.orig	2019-08-11 16:46:17.000000000 +0000
+++ zathura-pdf-mupdf/index.c
@@ -65,9 +65,11 @@ build_index(fz_context* ctx, fz_document
       float x = 0;
       float y = 0;
 
+      fz_location location = fz_resolve_link(ctx, document, outline->uri, &x, &y);
+
       type                    = ZATHURA_LINK_GOTO_DEST;
       target.destination_type = ZATHURA_LINK_DESTINATION_XYZ;
-      target.page_number      = fz_resolve_link(ctx, document, outline->uri, &x, &y);
+      target.page_number      = location.page;
       target.left  = x;
       target.top   = y;
       target.zoom  = 0.0;
