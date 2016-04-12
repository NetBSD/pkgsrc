$NetBSD: patch-glib_glibmm_ustring.cc,v 1.2 2016/04/12 21:27:25 adam Exp $

Work-around NetBSD's native iconv lacking support for WCHAR_T.

--- glib/glibmm/ustring.cc.orig	2016-02-29 09:31:32.000000000 +0000
+++ glib/glibmm/ustring.cc
@@ -1353,7 +1353,7 @@ ustring::FormatStream::to_string() const
 #ifdef GLIBMM_HAVE_WIDE_STREAM
   const std::wstring str = stream_.str();
 
-#if defined(__STDC_ISO_10646__) && SIZEOF_WCHAR_T == 4
+#if (defined(__STDC_ISO_10646__) || defined(__NetBSD__)) && SIZEOF_WCHAR_T == 4
   // Avoid going through iconv if wchar_t always contains UCS-4.
   glong n_bytes = 0;
   const auto buf = make_unique_ptr_gfree(g_ucs4_to_utf8(
@@ -1441,7 +1441,7 @@ operator>>(std::wistream& is, ustring& u
   std::wstring wstr;
   is >> wstr;
 
-#if defined(__STDC_ISO_10646__) && SIZEOF_WCHAR_T == 4
+#if (defined(__STDC_ISO_10646__) || defined(__NetBSD__)) && SIZEOF_WCHAR_T == 4
   // Avoid going through iconv if wchar_t always contains UCS-4.
   glong n_bytes = 0;
   const auto buf = make_unique_ptr_gfree(g_ucs4_to_utf8(
@@ -1472,7 +1472,7 @@ operator<<(std::wostream& os, const ustr
 {
   GError* error = nullptr;
 
-#if defined(__STDC_ISO_10646__) && SIZEOF_WCHAR_T == 4
+#if (defined(__STDC_ISO_10646__) || defined(__NetBSD__)) && SIZEOF_WCHAR_T == 4
   // Avoid going through iconv if wchar_t always contains UCS-4.
   const auto buf = make_unique_ptr_gfree(
     g_utf8_to_ucs4(utf8_string.raw().data(), utf8_string.raw().size(), nullptr, nullptr, &error));
