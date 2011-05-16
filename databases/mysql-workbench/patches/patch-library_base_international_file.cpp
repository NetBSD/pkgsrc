$NetBSD: patch-library_base_international_file.cpp,v 1.1.1.1 2011/05/16 12:40:50 adam Exp $

Use const string for iconv on all platforms.

--- library/base/international_file.cpp.orig	2011-05-16 08:33:28.000000000 +0000
+++ library/base/international_file.cpp
@@ -257,11 +257,7 @@ boost::int64_t read_char_from_intl_file(
   else
   {
     gunichar utf8_char= g_utf8_get_char(file->next_utf8_char);
-#ifdef _WIN32
     const char * cur_utf8_char= file->next_utf8_char;
-#else
-    char * cur_utf8_char= file->next_utf8_char;
-#endif
     file->next_utf8_char= g_utf8_next_char(file->next_utf8_char);
 
     *bytes_read= (int) (file->next_utf8_char - cur_utf8_char);
