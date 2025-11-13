$NetBSD: patch-src_core_node.c,v 1.1 2025/11/13 22:26:26 wiz Exp $

Fix calloc argument order.

--- src/core/node.c.orig	2023-12-27 15:52:07.000000000 +0000
+++ src/core/node.c
@@ -2379,7 +2379,7 @@ static inline dom_exception _dom_event_t
 	if (t == NULL) {
 		/* Create the event target list */
 		size = 64;
-		t = calloc(sizeof(*t), size);
+		t = calloc(size, sizeof(*t));
 		if (t == NULL) {
 			return DOM_NO_MEM_ERR;
 		}
