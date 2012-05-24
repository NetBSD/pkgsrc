$NetBSD: patch-library_base_international_file.cpp,v 1.2 2012/05/24 18:54:17 marino Exp $

--- library/base/international_file.cpp.orig	2011-03-17 12:48:42.000000000 +0000
+++ library/base/international_file.cpp
@@ -257,7 +257,7 @@ boost::int64_t read_char_from_intl_file(
   else
   {
     gunichar utf8_char= g_utf8_get_char(file->next_utf8_char);
-#ifdef _WIN32
+#ifndef __DragonFly__
     const char * cur_utf8_char= file->next_utf8_char;
 #else
     char * cur_utf8_char= file->next_utf8_char;
