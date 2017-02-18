$NetBSD: patch-index.c,v 1.3 2017/02/18 13:38:33 leot Exp $

Avoid possible NULL-pointer dereference.

--- index.c.orig	2017-01-11 21:21:14.000000000 +0000
+++ index.c
@@ -51,24 +51,26 @@ build_index(fz_context* ctx, fz_document
     zathura_link_type_t type               = ZATHURA_LINK_INVALID;
     zathura_rectangle_t rect               = { .x1 = 0, .y1 = 0, .x2 = 0, .y2 = 0 };
 
-    if (fz_is_external_link(ctx, outline->uri) == 1) {
-      if (strstr(outline->uri, "file://") == outline->uri) {
-        type         = ZATHURA_LINK_GOTO_REMOTE;
-        target.value = outline->uri;
+    if (outline->uri) {
+      if (fz_is_external_link(ctx, outline->uri) == 1) {
+        if (strstr(outline->uri, "file://") == outline->uri) {
+          type         = ZATHURA_LINK_GOTO_REMOTE;
+          target.value = outline->uri;
+        } else {
+          type         = ZATHURA_LINK_URI;
+          target.value = outline->uri;
+        }
       } else {
-        type         = ZATHURA_LINK_URI;
-        target.value = outline->uri;
+        float x = 0;
+        float y = 0;
+  
+        type                    = ZATHURA_LINK_GOTO_DEST;
+        target.destination_type = ZATHURA_LINK_DESTINATION_XYZ;
+        target.page_number      = fz_resolve_link(ctx, document, outline->uri, &x, &y);
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
-      target.page_number      = fz_resolve_link(ctx, document, outline->uri, &x, &y);
-      target.left  = x;
-      target.top   = y;
-      target.scale = 0.0;
     }
 
     index_element->link = zathura_link_new(type, rect, target);
