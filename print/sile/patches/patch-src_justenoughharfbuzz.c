$NetBSD: patch-src_justenoughharfbuzz.c,v 1.1 2026/01/06 15:49:29 ryoon Exp $

--- src/justenoughharfbuzz.c.orig	2026-01-03 09:56:09.216134040 +0000
+++ src/justenoughharfbuzz.c
@@ -178,7 +178,7 @@ int shape (lua_State *L) {
     hb_buffer_set_language(buf, hb_language_from_string(lang,strlen(lang)));
 
     hb_buffer_guess_segment_properties(buf);
-    int res = hb_shape_full (hbFont, buf, features, nFeatures, shaper_list);
+    int res = hb_shape_full (hbFont, buf, features, nFeatures, (const char * const *)shaper_list);
 
     if (direction == HB_DIRECTION_RTL) {
       hb_buffer_reverse(buf); /* URGH */
