$NetBSD: patch-glib_glibmm_ustring.cc,v 1.3 2019/04/26 15:12:20 bsiegert Exp $

Work-around NetBSD's native iconv lacking support for WCHAR_T.

--- glib/glibmm/ustring.cc.orig	2016-02-29 09:31:32.000000000 +0000
+++ glib/glibmm/ustring.cc
@@ -1364,7 +1364,7 @@ ustring::FormatStream::to_string() const
 #ifdef GLIBMM_HAVE_WIDE_STREAM
   const std::wstring str = stream_.str();
 
-#if (defined(__STDC_ISO_10646__) || defined(_LIBCPP_VERSION)) && SIZEOF_WCHAR_T == 4
+#if (defined(__STDC_ISO_10646__) || defined(_LIBCPP_VERSION) || defined(__NetBSD__)) && SIZEOF_WCHAR_T == 4
   // Avoid going through iconv if wchar_t always contains UCS-4.
   glong n_bytes = 0;
   const auto buf = make_unique_ptr_gfree(g_ucs4_to_utf8(
@@ -1452,7 +1452,7 @@ operator>>(std::wistream& is, ustring& u
   std::wstring wstr;
   is >> wstr;
 
-#if (defined(__STDC_ISO_10646__) || defined(_LIBCPP_VERSION)) && SIZEOF_WCHAR_T == 4
+#if (defined(__STDC_ISO_10646__) || defined(_LIBCPP_VERSION) || defined(__NetBSD__)) && SIZEOF_WCHAR_T == 4
   // Avoid going through iconv if wchar_t always contains UCS-4.
   glong n_bytes = 0;
   const auto buf = make_unique_ptr_gfree(g_ucs4_to_utf8(
@@ -1483,7 +1483,7 @@ operator<<(std::wostream& os, const ustr
 {
   GError* error = nullptr;
 
-#if (defined(__STDC_ISO_10646__) || defined(_LIBCPP_VERSION)) && SIZEOF_WCHAR_T == 4
+#if (defined(__STDC_ISO_10646__) || defined(_LIBCPP_VERSION) || defined(__NetBSD__)) && SIZEOF_WCHAR_T == 4
   // Avoid going through iconv if wchar_t always contains UCS-4.
   const auto buf = make_unique_ptr_gfree(
     g_utf8_to_ucs4(utf8_string.raw().data(), utf8_string.raw().size(), nullptr, nullptr, &error));
