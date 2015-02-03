$NetBSD: patch-glib_glibmm_ustring.cc,v 1.1 2015/02/03 11:50:43 adam Exp $

Work-around NetBSD's native iconv lacking support for WCHAR_T.

--- glib/glibmm/ustring.cc.orig	2015-02-03 11:32:45.000000000 +0000
+++ glib/glibmm/ustring.cc
@@ -1265,7 +1265,7 @@ ustring ustring::FormatStream::to_string
 #ifdef GLIBMM_HAVE_WIDE_STREAM
   const std::wstring str = stream_.str();
 
-# if defined(__STDC_ISO_10646__) && SIZEOF_WCHAR_T == 4
+# if (defined(__STDC_ISO_10646__) || defined(__NetBSD__)) && SIZEOF_WCHAR_T == 4
   // Avoid going through iconv if wchar_t always contains UCS-4.
   glong n_bytes = 0;
   const ScopedPtr<char> buf (g_ucs4_to_utf8(reinterpret_cast<const gunichar*>(str.data()),
@@ -1349,7 +1349,7 @@ std::wistream& operator>>(std::wistream&
   std::wstring wstr;
   is >> wstr;
 
-#if defined(__STDC_ISO_10646__) && SIZEOF_WCHAR_T == 4
+#if (defined(__STDC_ISO_10646__) || defined(__NetBSD__)) && SIZEOF_WCHAR_T == 4
   // Avoid going through iconv if wchar_t always contains UCS-4.
   glong n_bytes = 0;
   const ScopedPtr<char> buf (g_ucs4_to_utf8(reinterpret_cast<const gunichar*>(wstr.data()),
@@ -1380,7 +1380,7 @@ std::wostream& operator<<(std::wostream&
 {
   GError* error = 0;
 
-#if defined(__STDC_ISO_10646__) && SIZEOF_WCHAR_T == 4
+#if (defined(__STDC_ISO_10646__) || defined(__NetBSD__)) && SIZEOF_WCHAR_T == 4
   // Avoid going through iconv if wchar_t always contains UCS-4.
   const ScopedPtr<gunichar> buf (g_utf8_to_ucs4(utf8_string.raw().data(),
                                                 utf8_string.raw().size(), 0, 0, &error));
