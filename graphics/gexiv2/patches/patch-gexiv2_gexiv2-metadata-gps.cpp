$NetBSD: patch-gexiv2_gexiv2-metadata-gps.cpp,v 1.1 2023/07/01 22:14:58 wiz Exp $

Fix build with exiv2 0.28.0.
https://gitlab.gnome.org/GNOME/gexiv2/-/commit/06adc8fb70cb8c77c0cd364195d8251811106ef8

--- gexiv2/gexiv2-metadata-gps.cpp.orig	2023-05-06 08:50:03.000000000 +0000
+++ gexiv2/gexiv2-metadata-gps.cpp
@@ -90,7 +90,7 @@ gboolean gexiv2_metadata_try_get_gps_lon
 
         return TRUE;
     } catch (Exiv2::Error &e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     } catch (std::invalid_argument &e) {
         g_set_error_literal(error, g_quark_from_string("GExiv2"), 0, e.what());
     }
@@ -141,7 +141,7 @@ gboolean gexiv2_metadata_try_get_gps_lat
 
         return TRUE;
     } catch (Exiv2::Error &e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     } catch (std::invalid_argument &e) {
         g_set_error_literal(error, g_quark_from_string("GExiv2"), 0, e.what());
     }
@@ -181,7 +181,7 @@ gboolean gexiv2_metadata_try_get_gps_alt
 
         return TRUE;
     } catch (Exiv2::Error &e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     } catch (std::invalid_argument &e) {
         g_set_error_literal(error, g_quark_from_string("GExiv2"), 0, e.what());
     }
@@ -300,7 +300,7 @@ gboolean gexiv2_metadata_try_set_gps_inf
 
         return gexiv2_metadata_try_update_gps_info (self, longitude, latitude, altitude, error);
     } catch (Exiv2::Error &e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return FALSE;
@@ -393,7 +393,7 @@ gboolean gexiv2_metadata_try_update_gps_
         
         return TRUE;
     } catch (Exiv2::Error &e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return FALSE;
@@ -434,7 +434,7 @@ void gexiv2_metadata_try_delete_gps_info
                 ++exif_it;
         }
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     /* FIXME: two blocks shall ensure to erase in xmp data, if erasing in exif
@@ -454,7 +454,7 @@ void gexiv2_metadata_try_delete_gps_info
         
     } catch (Exiv2::Error& e) {
         if (error && *error == nullptr)
-            g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+            g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 }
 
