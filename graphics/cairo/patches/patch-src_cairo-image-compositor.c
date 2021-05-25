$NetBSD: patch-src_cairo-image-compositor.c,v 1.1 2021/05/25 07:29:42 nia Exp $

Fix mask usage in image-compositor

https://gitlab.freedesktop.org/cairo/cairo/-/merge_requests/85
https://gitlab.freedesktop.org/cairo/cairo/-/issues/437
https://nvd.nist.gov/vuln/detail/CVE-2020-35492

--- src/cairo-image-compositor.c.orig	2018-08-17 01:10:53.000000000 +0000
+++ src/cairo-image-compositor.c
@@ -2601,14 +2601,14 @@ _inplace_src_spans (void *abstract_rende
 		    unsigned num_spans)
 {
     cairo_image_span_renderer_t *r = abstract_renderer;
-    uint8_t *m;
+    uint8_t *m, *base = (uint8_t*)pixman_image_get_data(r->mask);
     int x0;
 
     if (num_spans == 0)
 	return CAIRO_STATUS_SUCCESS;
 
     x0 = spans[0].x;
-    m = r->_buf;
+    m = base;
     do {
 	int len = spans[1].x - spans[0].x;
 	if (len >= r->u.composite.run_length && spans[0].coverage == 0xff) {
@@ -2646,7 +2646,7 @@ _inplace_src_spans (void *abstract_rende
 				      spans[0].x, y,
 				      spans[1].x - spans[0].x, h);
 
-	    m = r->_buf;
+	    m = base;
 	    x0 = spans[1].x;
 	} else if (spans[0].coverage == 0x0) {
 	    if (spans[0].x != x0) {
@@ -2675,7 +2675,7 @@ _inplace_src_spans (void *abstract_rende
 #endif
 	    }
 
-	    m = r->_buf;
+	    m = base;
 	    x0 = spans[1].x;
 	} else {
 	    *m++ = spans[0].coverage;
