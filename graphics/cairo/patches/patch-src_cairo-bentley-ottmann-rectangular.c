$NetBSD: patch-src_cairo-bentley-ottmann-rectangular.c,v 1.1 2025/08/14 10:14:49 wiz Exp $

Fix for CVE-2025-50422.
https://gitlab.freedesktop.org/cairo/cairo/-/merge_requests/632

--- src/cairo-bentley-ottmann-rectangular.c.orig	2025-03-08 12:35:35.000000000 +0000
+++ src/cairo-bentley-ottmann-rectangular.c
@@ -847,12 +847,16 @@ _cairo_bentley_ottmann_tessellate_boxes 
 		rectangles[j].left.x = box[i].p2.x;
 		rectangles[j].left.dir = -1;
 	    }
+	    if (unlikely (rectangles[j].left.x == INT32_MAX)) rectangles[j].left.x = INT32_MAX-1;
+	    if (unlikely (rectangles[j].right.x == INT32_MAX)) rectangles[j].right.x = INT32_MAX-1;
 
 	    rectangles[j].left.right = NULL;
 	    rectangles[j].right.right = NULL;
 
 	    rectangles[j].top = box[i].p1.y;
 	    rectangles[j].bottom = box[i].p2.y;
+	    if (unlikely (rectangles[j].top == INT32_MIN)) rectangles[j].top = INT32_MIN+1;
+	    if (unlikely (rectangles[j].bottom == INT32_MIN)) rectangles[j].bottom = INT32_MIN+1;
 
 	    if (rectangles_chain) {
 		h = _cairo_fixed_integer_floor (box[i].p1.y) - y_min;
