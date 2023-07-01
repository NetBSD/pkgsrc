$NetBSD: patch-gexiv2_gexiv2-metadata-xmp.cpp,v 1.1 2023/07/01 22:14:58 wiz Exp $

Fix build with exiv2 0.28.0.
https://gitlab.gnome.org/GNOME/gexiv2/-/commit/06adc8fb70cb8c77c0cd364195d8251811106ef8

--- gexiv2/gexiv2-metadata-xmp.cpp.orig	2023-05-06 08:50:03.000000000 +0000
+++ gexiv2/gexiv2-metadata-xmp.cpp
@@ -8,6 +8,8 @@
  * SPDX-License-Identifier: GPL-2.0-or-later
  */
 
+#include <config.h>
+
 #include "gexiv2-metadata-private.h"
 #include "gexiv2-metadata.h"
 
@@ -48,7 +50,7 @@ gchar *gexiv2_metadata_try_generate_xmp_
             return g_strdup(packet.c_str());
         }
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return nullptr;
@@ -79,7 +81,7 @@ gchar *gexiv2_metadata_try_get_xmp_packe
     try {
         return g_strdup(self->priv->image->xmpPacket().c_str());
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return NULL;
@@ -187,7 +189,7 @@ gchar* gexiv2_metadata_get_xmp_tag_strin
         if (it != xmp_data.end())
             return g_strdup (it->toString ().c_str ());
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return nullptr;
@@ -214,7 +216,7 @@ gchar* gexiv2_metadata_get_xmp_tag_inter
             return g_strdup (os.str ().c_str ());
         }
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return nullptr;
@@ -257,7 +259,7 @@ gboolean gexiv2_metadata_try_set_xmp_tag
         xmp_data.add(Exiv2::XmpKey(tag), &tv);
         return TRUE;
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return FALSE;
@@ -294,7 +296,7 @@ gboolean gexiv2_metadata_set_xmp_tag_str
         
         return TRUE;
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return FALSE;
@@ -313,11 +315,16 @@ glong gexiv2_metadata_get_xmp_tag_long (
         Exiv2::XmpData::iterator it = xmp_data.findKey(Exiv2::XmpKey(tag));
         while (it != xmp_data.end() && it->count() == 0)
             it++;
-        
+
+#ifdef EXIV2_XMPDATUM_HAS_TO_LONG
         if (it != xmp_data.end())
             return it->toLong ();
+#else
+        if (it != xmp_data.end())
+            return static_cast<glong>(it->toInt64());
+#endif
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return 0;
@@ -334,7 +341,7 @@ gboolean gexiv2_metadata_set_xmp_tag_lon
         
         return TRUE;
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return FALSE;
@@ -414,7 +421,7 @@ gchar** gexiv2_metadata_get_xmp_tag_mult
         if (array) {
             g_strfreev(array);
         }
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     array = g_new(gchar*, 1);
@@ -450,7 +457,7 @@ gchar** gexiv2_metadata_get_xmp_tag_mult
             return array;
         }
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     gchar **array = g_new (gchar*, 1);
@@ -488,7 +495,7 @@ gboolean gexiv2_metadata_set_xmp_tag_mul
 
         return TRUE;
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return FALSE;
@@ -501,7 +508,7 @@ const gchar* gexiv2_metadata_get_xmp_tag
     try {
         return Exiv2::XmpProperties::propertyTitle(Exiv2::XmpKey(tag));
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return NULL;
@@ -514,7 +521,7 @@ const gchar* gexiv2_metadata_get_xmp_tag
     try {
         return Exiv2::XmpProperties::propertyDesc(Exiv2::XmpKey(tag));
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return NULL;
@@ -527,7 +534,7 @@ const gchar* gexiv2_metadata_get_xmp_tag
     try {
         return Exiv2::TypeInfo::typeName(Exiv2::XmpProperties::propertyType(Exiv2::XmpKey(tag)));
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return NULL;
@@ -569,7 +576,7 @@ gboolean gexiv2_metadata_xmp_tag_support
             return TRUE;
         }
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     return FALSE;
 }
@@ -597,7 +604,7 @@ GBytes* gexiv2_metadata_get_xmp_tag_raw 
             }
         }
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return nullptr;
@@ -622,15 +629,21 @@ gboolean gexiv2_metadata_try_register_xm
     g_return_val_if_fail(prefix != nullptr, FALSE);
     g_return_val_if_fail(error == nullptr || *error == nullptr, FALSE);
 
+#if defined(EXIV2_HAS_ANY_ERROR)
+    using Exiv2ErrorProxy = Exiv2::AnyError;
+#else
+    using Exiv2ErrorProxy = Exiv2::Error;
+#endif
+
     try {
         Exiv2::XmpProperties::ns(prefix);
-    } catch (Exiv2::AnyError& e1) {
+    } catch (Exiv2ErrorProxy& e1) {
         // No namespace, OK to register
         try {
             Exiv2::XmpProperties::registerNs(name, prefix);
             return TRUE;
-        } catch (Exiv2::AnyError& e2) {
-            g_set_error_literal(error, g_quark_from_string("GExiv2"), e2.code(), e2.what());
+        } catch (Exiv2ErrorProxy& e2) {
+            g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e2.code()), e2.what());
         }
     }
 
@@ -670,7 +683,7 @@ gboolean gexiv2_metadata_try_unregister_
             }
         }
     } catch (Exiv2::Error& e2) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e2.code(), e2.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e2.code()), e2.what());
     }
     return FALSE;
 }
@@ -692,7 +705,7 @@ void gexiv2_metadata_try_unregister_all_
     try {
         Exiv2::XmpProperties::unregisterNs();
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 }
 
@@ -739,7 +752,7 @@ char* gexiv2_metadata_try_get_xmp_namesp
 
         result = g_strdup(info.c_str());
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     g_clear_pointer(&list, g_strfreev);
