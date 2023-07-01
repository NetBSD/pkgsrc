$NetBSD: patch-gexiv2_gexiv2-metadata-iptc.cpp,v 1.1 2023/07/01 22:14:58 wiz Exp $

Fix build with exiv2 0.28.0.
https://gitlab.gnome.org/GNOME/gexiv2/-/commit/06adc8fb70cb8c77c0cd364195d8251811106ef8

--- gexiv2/gexiv2-metadata-iptc.cpp.orig	2023-05-06 08:50:03.000000000 +0000
+++ gexiv2/gexiv2-metadata-iptc.cpp
@@ -140,7 +140,7 @@ gchar* gexiv2_metadata_get_iptc_tag_stri
             return g_strdup (os.str().c_str());
         }
     } catch (Exiv2::Error& e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return nullptr;
@@ -186,7 +186,7 @@ gchar* gexiv2_metadata_get_iptc_tag_inte
             return g_strdup (os.str().c_str());
         }
     } catch (Exiv2::Error& e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return nullptr;
@@ -234,7 +234,7 @@ gboolean gexiv2_metadata_set_iptc_tag_st
 
         return TRUE;
     } catch (Exiv2::Error& e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return FALSE;
@@ -271,7 +271,7 @@ gchar** gexiv2_metadata_get_iptc_tag_mul
         
         return values;
     } catch (Exiv2::Error& e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     g_slist_free_full (list, g_free);
@@ -347,7 +347,7 @@ gboolean gexiv2_metadata_set_iptc_tag_mu
 
         return TRUE;
     } catch (Exiv2::Error& e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return FALSE;
@@ -361,7 +361,7 @@ const gchar* gexiv2_metadata_get_iptc_ta
         Exiv2::IptcKey key (tag);
         return Exiv2::IptcDataSets::dataSetTitle (key.tag (), key.record ());
     } catch (Exiv2::Error& e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return NULL;
@@ -375,7 +375,7 @@ const gchar* gexiv2_metadata_get_iptc_ta
         Exiv2::IptcKey key (tag);
         return Exiv2::IptcDataSets::dataSetDesc (key.tag (), key.record ());
     } catch (Exiv2::Error& e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return NULL;
@@ -389,7 +389,7 @@ const gchar* gexiv2_metadata_get_iptc_ta
         Exiv2::IptcKey key (tag);
         return Exiv2::TypeInfo::typeName(Exiv2::IptcDataSets::dataSetType(key.tag(), key.record()));
     } catch (Exiv2::Error& e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     
     return NULL;
@@ -403,7 +403,7 @@ gboolean gexiv2_metadata_iptc_tag_suppor
         const Exiv2::IptcKey key(tag); // Check to see if @tag is valid
         return (Exiv2::IptcDataSets::dataSetRepeatable(key.tag(), key.record()) ? TRUE : FALSE);
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return FALSE;
@@ -464,7 +464,7 @@ GBytes* gexiv2_metadata_get_iptc_tag_raw
             return g_byte_array_free_to_bytes(concatenated_raw_arrays);
         }
     } catch (Exiv2::Error& e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return nullptr;
