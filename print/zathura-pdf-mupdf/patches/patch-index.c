$NetBSD: patch-index.c,v 1.4 2017/12/18 15:07:14 leot Exp $

index: handle outline entries with no URI

Some PDFs (such as [1]) cause mupdf to return outline elements with a
NULL uri element, which causes a NULL pointer dereference to happen in
fz_is_external_link.

Catch this case, but still create a dummy entry in the outline.

[1] http://www.st.com/resource/en/reference_manual/dm00093941.pdf

Signed-off-by: Florian Larysch <fl@n621.de>

Backported from upstream, commit 74deda65003386df216c7c0343c86d95c866f5e1.

--- index.c.orig	2017-01-11 21:21:14.000000000 +0000
+++ index.c
@@ -51,7 +51,9 @@ build_index(fz_context* ctx, fz_document
     zathura_link_type_t type               = ZATHURA_LINK_INVALID;
     zathura_rectangle_t rect               = { .x1 = 0, .y1 = 0, .x2 = 0, .y2 = 0 };
 
-    if (fz_is_external_link(ctx, outline->uri) == 1) {
+    if (outline->uri == NULL) {
+      type = ZATHURA_LINK_NONE;
+    } else if (fz_is_external_link(ctx, outline->uri) == 1) {
       if (strstr(outline->uri, "file://") == outline->uri) {
         type         = ZATHURA_LINK_GOTO_REMOTE;
         target.value = outline->uri;
