$NetBSD: patch-gexiv2_gexiv2-preview-image.cpp,v 1.1 2023/07/01 22:14:59 wiz Exp $

Fix build with exiv2 0.28.0.
https://gitlab.gnome.org/GNOME/gexiv2/-/commit/06adc8fb70cb8c77c0cd364195d8251811106ef8

--- gexiv2/gexiv2-preview-image.cpp.orig	2023-05-06 08:50:03.000000000 +0000
+++ gexiv2/gexiv2-preview-image.cpp
@@ -66,7 +66,7 @@ GExiv2PreviewImage* gexiv2_preview_image
 
         g_object_unref(self);
 
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     return nullptr;
 }
@@ -141,7 +141,7 @@ glong gexiv2_preview_image_try_write_fil
     try {
         return self->priv->image->writeFile(path);
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     return -1;
 }
