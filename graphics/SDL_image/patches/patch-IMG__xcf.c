$NetBSD: patch-IMG__xcf.c,v 1.1 2025/10/04 14:38:43 kikadf Exp $

* Fix CVE-2017-2887,
  https://github.com/libsdl-org/SDL_image/commit/e7723676825cd2b2ffef3316ec1879d7726618f2

--- IMG_xcf.c.orig	2025-10-04 14:31:21.599190567 +0000
+++ IMG_xcf.c
@@ -251,6 +251,7 @@ static Uint32 Swap32 (Uint32 v) {
 }
 
 static void xcf_read_property (SDL_RWops * src, xcf_prop * prop) {
+  Uint32 len;
   prop->id = SDL_ReadBE32 (src);
   prop->length = SDL_ReadBE32 (src);
 
@@ -274,7 +275,12 @@ static void xcf_read_property (SDL_RWops
     break;
   case PROP_COMPRESSION:
   case PROP_COLOR:
-    SDL_RWread (src, &prop->data, prop->length, 1);
+    if (prop->length > sizeof(prop->data)) {
+        len = sizeof(prop->data);
+    } else {
+        len = prop->length;
+    }
+    SDL_RWread(src, &prop->data, len, 1);
     break;
   case PROP_VISIBLE:
     prop->data.visible = SDL_ReadBE32 (src);
