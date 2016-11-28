$NetBSD: patch-index.c,v 1.1 2016/11/28 14:41:40 leot Exp $

Update to mupdf-1.10 API.

--- index.c.orig	2016-02-14 22:49:46.000000000 +0000
+++ index.c
@@ -6,7 +6,7 @@
 
 #include "plugin.h"
 
-static void build_index(fz_outline* outline, girara_tree_node_t* root);
+static void build_index(mupdf_document_t* mupdf_document, fz_outline* outline, girara_tree_node_t* root);
 
 girara_tree_node_t*
 pdf_document_index_generate(zathura_document_t* document, mupdf_document_t* mupdf_document, zathura_error_t* error)
@@ -29,7 +29,7 @@ pdf_document_index_generate(zathura_docu
 
   /* generate index */
   girara_tree_node_t* root = girara_node_new(zathura_index_element_new("ROOT"));
-  build_index(outline, root);
+  build_index(mupdf_document, outline, root);
 
   /* free outline */
   fz_drop_outline(mupdf_document->ctx, outline);
@@ -38,7 +38,7 @@ pdf_document_index_generate(zathura_docu
 }
 
 static void
-build_index(fz_outline* outline, girara_tree_node_t* root)
+build_index(mupdf_document_t* mupdf_document, fz_outline* outline, girara_tree_node_t* root)
 {
   if (outline == NULL || root == NULL) {
     return;
@@ -50,49 +50,24 @@ build_index(fz_outline* outline, girara_
     zathura_link_type_t type               = ZATHURA_LINK_INVALID;
     zathura_rectangle_t rect               = { .x1 = 0, .y1 = 0, .x2 = 0, .y2 = 0 };
 
-    switch (outline->dest.kind) {
-      case FZ_LINK_NONE:
-        type = ZATHURA_LINK_NONE;
-        break;
-      case FZ_LINK_URI:
+    if (fz_is_external_link(mupdf_document->ctx, outline->uri)) {
         type         = ZATHURA_LINK_URI;
-        target.value = outline->dest.ld.uri.uri;
-        break;
-      case FZ_LINK_GOTO:
+        target.value = outline->uri;
+    } else if (outline->uri) {
+        float tx, ty;
+        tx                      = 0.0;
+        ty                      = 0.0;
         type                    = ZATHURA_LINK_GOTO_DEST;
-        target.page_number      = outline->dest.ld.gotor.page;
+        target.page_number      = 0;
         target.destination_type = ZATHURA_LINK_DESTINATION_XYZ;
-        target.left             = 0;
-        target.top              = 0;
+        target.left             = 0.0;
+        target.top              = 0.0;
         target.scale            = 0.0;
-        {
-          int gflags = outline->dest.ld.gotor.flags;
-          if (gflags & fz_link_flag_l_valid) {
-            target.left = outline->dest.ld.gotor.lt.x;
-          }
-          if (gflags & fz_link_flag_t_valid) {
-            target.top = outline->dest.ld.gotor.lt.y;
-          }
-          /* if (gflags & fz_link_flag_r_is_zoom) { */
-          /*   target.scale = outline->dest.ld.gotor.rb.x; */
-          /* } */
-        }
-        break;
-      case FZ_LINK_LAUNCH:
-        type = ZATHURA_LINK_LAUNCH;
-        target.value = outline->dest.ld.launch.file_spec;
-        break;
-      case FZ_LINK_NAMED:
-        type = ZATHURA_LINK_NAMED;
-        target.value = outline->dest.ld.named.named;
-        break;
-      case FZ_LINK_GOTOR:
-        type = ZATHURA_LINK_GOTO_REMOTE;
-        target.value = outline->dest.ld.gotor.file_spec;
-        break;
-      default:
-        outline = outline->next; // TODO: Don't skip unknown type
-        continue;
+	target.page_number = fz_resolve_link(mupdf_document->ctx, mupdf_document->document, outline->uri, &tx, &ty);
+        target.left             = tx;
+        target.top              = ty;
+    } else {
+        type = ZATHURA_LINK_NONE;
     }
 
     index_element->link = zathura_link_new(type, rect, target);
@@ -104,7 +79,7 @@ build_index(fz_outline* outline, girara_
     girara_tree_node_t* node = girara_node_append_data(root, index_element);
 
     if (outline->down != NULL) {
-      build_index(outline->down, node);
+      build_index(mupdf_document, outline->down, node);
     }
 
     outline = outline->next;
