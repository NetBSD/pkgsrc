$NetBSD: patch-src_support_strfwd.h,v 1.1 2012/11/23 12:32:00 joerg Exp $

--- src/support/strfwd.h.orig	2012-11-22 21:47:30.000000000 +0000
+++ src/support/strfwd.h
@@ -28,28 +28,8 @@ namespace lyx { typedef boost::uint32_t 
 
 #endif
 
-
-namespace std {
-
-template<typename Alloc> class allocator;
-
-template<typename Char> struct char_traits;
-template<> struct char_traits<char>;
-#ifdef USE_WCHAR_T
-template<> struct char_traits<wchar_t>;
-#endif
-
-template<typename Char, typename Traits, typename Alloc> class basic_string;
-typedef basic_string<char, char_traits<char>, allocator<char> > string;
-
-template<class Char, class Traits> class basic_istream;
-template<class Char, class Traits> class basic_ostream;
-
-typedef basic_istream<char, char_traits<char> > istream;
-typedef basic_ostream<char, char_traits<char> > ostream;
-
-} // namepace std
-
+#include <string>
+#include <iostream>
 
 namespace lyx {
 
