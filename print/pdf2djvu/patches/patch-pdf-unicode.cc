$NetBSD: patch-pdf-unicode.cc,v 1.3 2026/06/24 21:57:36 wiz Exp $

Fix build with poppler 26.06.
From Arch.
https://aur.archlinux.org/cgit/aur.git/plain/pdf2djvu-poppler-26.01.0.patch?h=pdf2djvu
https://aur.archlinux.org/cgit/aur.git/plain/pdf2djvu-poppler-26.x.patch?h=pdf2djvu

--- pdf-unicode.cc.orig	2022-08-09 20:28:01.000000000 +0000
+++ pdf-unicode.cc
@@ -49,7 +49,7 @@ std::string pdf::string_as_utf8(const pdf::String *str
      */
     const static uint32_t replacement_character = 0xFFFD;
     const char *cstring = pdf::get_c_string(string);
-    size_t clength = string->getLength();
+    size_t clength = string->size();
     std::ostringstream stream;
     if (clength >= 2 && (cstring[0] & 0xFF) == 0xFE && (cstring[1] & 0xFF) == 0xFF) {
         /* UTF-16-BE Byte Order Mark */
@@ -105,7 +105,12 @@ std::string pdf::string_as_utf8(pdf::Object &object)
 
 std::string pdf::string_as_utf8(pdf::Object &object)
 {
+#if POPPLER_VERSION > 260300
+    pdf::String str = pdf::String(object.getString());
+    return pdf::string_as_utf8(&str);
+#else
     return pdf::string_as_utf8(object.getString());
+#endif
 }
 
 /* class pdf::FullNFKC
