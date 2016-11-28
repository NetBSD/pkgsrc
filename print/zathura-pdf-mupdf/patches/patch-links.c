$NetBSD: patch-links.c,v 1.1 2016/11/28 14:41:40 leot Exp $

Update to mupdf-1.10 API.

--- links.c.orig	2016-02-14 22:49:46.000000000 +0000
+++ links.c
@@ -44,48 +44,22 @@ pdf_page_links_get(zathura_page_t* page,
     zathura_link_target_t target = { 0 };
 
     char* buffer = NULL;
-    switch (link->dest.kind) {
-      case FZ_LINK_NONE:
-        type = ZATHURA_LINK_NONE;
-        break;
-      case FZ_LINK_URI:
+    if (fz_is_external_link(mupdf_document->ctx, link->uri)) {
         type         = ZATHURA_LINK_URI;
-        target.value = link->dest.ld.uri.uri;
-        break;
-      case FZ_LINK_GOTO:
+        target.value = link->uri;
+    } else {
+        float tx, ty;
+        tx                      = 0.0;
+        ty                      = 0.0;
         type                    = ZATHURA_LINK_GOTO_DEST;
-        target.page_number      = link->dest.ld.gotor.page;
+        target.page_number      = 0;
         target.destination_type = ZATHURA_LINK_DESTINATION_XYZ;
-        target.left             = 0;
-        target.top              = 0;
+        target.left             = 0.0;
+        target.top              = 0.0;
         target.scale            = 0.0;
-        {
-          int gflags = link->dest.ld.gotor.flags;
-          if (gflags & fz_link_flag_l_valid) {
-            target.left = link->dest.ld.gotor.lt.x;
-          }
-          if (gflags & fz_link_flag_t_valid) {
-            target.top = link->dest.ld.gotor.lt.y;
-          }
-          /* if (gflags & fz_link_flag_r_is_zoom) { */
-          /*   target.scale = link->dest.ld.gotor.rb.x; */
-          /* } */
-        }
-        break;
-      case FZ_LINK_LAUNCH:
-        type = ZATHURA_LINK_LAUNCH;
-        target.value = link->dest.ld.launch.file_spec;
-        break;
-      case FZ_LINK_NAMED:
-        type = ZATHURA_LINK_NAMED;
-        target.value = link->dest.ld.named.named;
-        break;
-      case FZ_LINK_GOTOR:
-        type = ZATHURA_LINK_GOTO_REMOTE;
-        target.value = link->dest.ld.gotor.file_spec;
-        break;
-      default:
-        continue;
+        target.page_number = fz_resolve_link(mupdf_document->ctx, mupdf_document->document, link->uri, &tx, &ty);
+        target.left             = tx;
+        target.top              = ty;
     }
 
     zathura_link_t* zathura_link = zathura_link_new(type, position, target);
