$NetBSD: patch-gexiv2_gexiv2-metadata-exif.cpp,v 1.1 2023/07/01 22:14:58 wiz Exp $

Fix build with exiv2 0.28.0.
https://gitlab.gnome.org/GNOME/gexiv2/-/commit/06adc8fb70cb8c77c0cd364195d8251811106ef8

--- gexiv2/gexiv2-metadata-exif.cpp.orig	2023-05-06 08:50:03.000000000 +0000
+++ gexiv2/gexiv2-metadata-exif.cpp
@@ -8,6 +8,8 @@
  * SPDX-License-Identifier: GPL-2.0-or-later
  */
 
+#include <config.h>
+
 #include "gexiv2-metadata.h"
 #include "gexiv2-metadata-private.h"
 #include <string>
@@ -116,7 +118,7 @@ gchar* gexiv2_metadata_get_exif_tag_stri
         if (it != exif_data.end())
             return g_strdup (it->toString ().c_str ());
     } catch (Exiv2::Error& e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return nullptr;
@@ -146,7 +148,7 @@ gchar** gexiv2_metadata_get_exif_tag_mul
             return array;
         }
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     array = g_new(gchar*, 1);
@@ -187,7 +189,7 @@ gboolean gexiv2_metadata_set_exif_tag_mu
         }
         return TRUE;
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return FALSE;
@@ -214,7 +216,7 @@ gchar* gexiv2_metadata_get_exif_tag_inte
             return g_strdup (os.str ().c_str ());
         }
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return nullptr;
@@ -232,7 +234,7 @@ gboolean gexiv2_metadata_set_exif_tag_st
         
         return TRUE;
     } catch (Exiv2::Error& e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return FALSE;
@@ -251,11 +253,15 @@ glong gexiv2_metadata_get_exif_tag_long 
         Exiv2::ExifData::iterator it = exif_data.findKey(Exiv2::ExifKey(tag));
         while (it != exif_data.end() && it->count() == 0)
             it++;
-        
+#ifdef EXIV2_EXIFDATUM_HAS_TO_LONG
         if (it != exif_data.end())
             return it->toLong ();
+#else
+        if (it != exif_data.end())
+            return static_cast<glong>(it->toInt64());
+#endif
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return 0;
@@ -272,7 +278,7 @@ gboolean gexiv2_metadata_set_exif_tag_lo
         
         return TRUE;
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return FALSE;
@@ -303,7 +309,7 @@ gboolean gexiv2_metadata_try_get_exif_ta
             return TRUE;
         }
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return FALSE;
@@ -324,7 +330,7 @@ gboolean gexiv2_metadata_try_set_exif_ta
         
         return TRUE;
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return FALSE;
@@ -413,7 +419,7 @@ const gchar* gexiv2_metadata_get_exif_ta
         Exiv2::ExifKey key(tag);
         return g_intern_string(key.tagLabel().c_str());
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return NULL;
@@ -427,7 +433,7 @@ const gchar* gexiv2_metadata_get_exif_ta
         Exiv2::ExifKey key(tag);
         return g_intern_string(key.tagDesc().c_str());
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return NULL;
@@ -441,7 +447,7 @@ const gchar* gexiv2_metadata_get_exif_ta
         Exiv2::ExifKey key(tag);
         return Exiv2::TypeInfo::typeName(key.defaultTypeId());
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return NULL;
@@ -455,7 +461,7 @@ gboolean gexiv2_metadata_exif_tag_suppor
     	// Exif does not support multiple values, but still check if @tag is valid
         const Exiv2::ExifKey key(tag);
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return FALSE;
@@ -484,7 +490,7 @@ GBytes* gexiv2_metadata_get_exif_tag_raw
             }
         }
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string ("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return nullptr;
@@ -522,7 +528,7 @@ GBytes * gexiv2_metadata_get_exif_data (
 
         return g_bytes_new_take (data, blob.size());
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return nullptr;
