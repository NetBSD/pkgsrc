$NetBSD: patch-libs_canvas_stateful__image.cc,v 1.1 2016/12/15 23:45:07 joerg Exp $

Use bool conversion, RefPtr doesn't compare to 0 in C++11 mode.

--- libs/canvas/stateful_image.cc.orig	2016-12-15 17:12:09.614013045 +0000
+++ libs/canvas/stateful_image.cc
@@ -108,7 +108,7 @@ StatefulImage::load_states (const XMLNod
 			continue;
 		}
 
-		if ((s.image = find_image (prop->value())) == 0) {
+		if (!(s.image = find_image (prop->value()))) {
 			error << string_compose (_("image %1 not found for state"), prop->value()) << endmsg;
 			continue;
 		}
