$NetBSD: patch-links.c,v 1.3 2017/02/18 13:38:33 leot Exp $

Avoid possible NULL-pointer dereference.

--- links.c.orig	2017-01-11 21:21:14.000000000 +0000
+++ links.c
@@ -43,25 +43,27 @@ pdf_page_links_get(zathura_page_t* page,
     zathura_link_type_t type     = ZATHURA_LINK_INVALID;
     zathura_link_target_t target = { 0 };
 
-    if (fz_is_external_link(mupdf_document->ctx, link->uri) == 1) {
-      if (strstr(link->uri, "file://") == link->uri) {
-        type         = ZATHURA_LINK_GOTO_REMOTE;
-        target.value = link->uri;
+    if (link->uri) {
+      if (fz_is_external_link(mupdf_document->ctx, link->uri) == 1) {
+        if (strstr(link->uri, "file://") == link->uri) {
+          type         = ZATHURA_LINK_GOTO_REMOTE;
+          target.value = link->uri;
+        } else {
+          type         = ZATHURA_LINK_URI;
+          target.value = link->uri;
+        }
       } else {
-        type         = ZATHURA_LINK_URI;
-        target.value = link->uri;
+        float x = 0;
+        float y = 0;
+  
+        type                    = ZATHURA_LINK_GOTO_DEST;
+        target.destination_type = ZATHURA_LINK_DESTINATION_XYZ;
+        target.page_number      = fz_resolve_link(mupdf_document->ctx,
+            mupdf_document->document, link->uri, &x, &y);
+        target.left  = x;
+        target.top   = y;
+        target.scale = 0.0;
       }
-    } else {
-      float x = 0;
-      float y = 0;
-
-      type                    = ZATHURA_LINK_GOTO_DEST;
-      target.destination_type = ZATHURA_LINK_DESTINATION_XYZ;
-      target.page_number      = fz_resolve_link(mupdf_document->ctx,
-          mupdf_document->document, link->uri, &x, &y);
-      target.left  = x;
-      target.top   = y;
-      target.scale = 0.0;
     }
 
     zathura_link_t* zathura_link = zathura_link_new(type, position, target);
