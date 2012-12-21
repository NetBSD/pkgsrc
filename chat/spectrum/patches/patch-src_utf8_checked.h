$NetBSD: patch-src_utf8_checked.h,v 1.1 2012/12/21 00:10:59 schnoebe Exp $

Reorder the template definitions so append() was defined in the class
before its first use.

--- src/utf8/checked.h.orig	2010-10-08 07:15:22.000000000 +0000
+++ src/utf8/checked.h
@@ -65,6 +65,35 @@ namespace utf8
 
     /// The library API - functions intended to be called by the users
 
+    template <typename octet_iterator>
+    octet_iterator append(uint32_t cp, octet_iterator result)
+    {
+        if (!internal::is_code_point_valid(cp))
+            throw invalid_code_point(cp);
+
+        if (cp < 0x80)                        // one octet
+            *(result++) = static_cast<uint8_t>(cp);
+        else if (cp < 0x800) {                // two octets
+            *(result++) = static_cast<uint8_t>((cp >> 6)            | 0xc0);
+            *(result++) = static_cast<uint8_t>((cp & 0x3f)          | 0x80);
+        }
+        else if (cp < 0x10000) {              // three octets
+            *(result++) = static_cast<uint8_t>((cp >> 12)           | 0xe0);
+            *(result++) = static_cast<uint8_t>(((cp >> 6) & 0x3f)     | 0x80);
+            *(result++) = static_cast<uint8_t>((cp & 0x3f)          | 0x80);
+        }
+        else if (cp <= internal::CODE_POINT_MAX) {      // four octets
+            *(result++) = static_cast<uint8_t>((cp >> 18)           | 0xf0);
+            *(result++) = static_cast<uint8_t>(((cp >> 12)& 0x3f)     | 0x80);
+            *(result++) = static_cast<uint8_t>(((cp >> 6) & 0x3f)     | 0x80);
+            *(result++) = static_cast<uint8_t>((cp & 0x3f)          | 0x80);
+        }
+        else
+            throw invalid_code_point(cp);
+
+        return result;
+    }
+
     template <typename octet_iterator, typename output_iterator>
     output_iterator replace_invalid(octet_iterator start, octet_iterator end, output_iterator out, uint32_t replacement)
     {
@@ -104,35 +133,6 @@ namespace utf8
     }
 
     template <typename octet_iterator>
-    octet_iterator append(uint32_t cp, octet_iterator result)
-    {
-        if (!internal::is_code_point_valid(cp))
-            throw invalid_code_point(cp);
-
-        if (cp < 0x80)                        // one octet
-            *(result++) = static_cast<uint8_t>(cp);
-        else if (cp < 0x800) {                // two octets
-            *(result++) = static_cast<uint8_t>((cp >> 6)            | 0xc0);
-            *(result++) = static_cast<uint8_t>((cp & 0x3f)          | 0x80);
-        }
-        else if (cp < 0x10000) {              // three octets
-            *(result++) = static_cast<uint8_t>((cp >> 12)           | 0xe0);
-            *(result++) = static_cast<uint8_t>(((cp >> 6) & 0x3f)     | 0x80);
-            *(result++) = static_cast<uint8_t>((cp & 0x3f)          | 0x80);
-        }
-        else if (cp <= internal::CODE_POINT_MAX) {      // four octets
-            *(result++) = static_cast<uint8_t>((cp >> 18)           | 0xf0);
-            *(result++) = static_cast<uint8_t>(((cp >> 12)& 0x3f)     | 0x80);
-            *(result++) = static_cast<uint8_t>(((cp >> 6) & 0x3f)     | 0x80);
-            *(result++) = static_cast<uint8_t>((cp & 0x3f)          | 0x80);
-        }
-        else
-            throw invalid_code_point(cp);
-
-        return result;
-    }
-
-    template <typename octet_iterator>
     uint32_t next(octet_iterator& it, octet_iterator end)
     {
         uint32_t cp = 0;
