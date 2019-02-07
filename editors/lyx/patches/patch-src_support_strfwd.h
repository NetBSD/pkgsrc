$NetBSD: patch-src_support_strfwd.h,v 1.3 2019/02/07 10:42:48 markd Exp $

--- src/support/strfwd.h.orig	2018-12-09 20:04:52.000000000 +0000
+++ src/support/strfwd.h
@@ -42,28 +42,8 @@ namespace lyx { typedef boost::uint32_t 
 #include <string>
 #else
 
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
-template<class Char, class Traits, class Allocator> class basic_ostringstream;
-
-typedef basic_istream<char, char_traits<char> > istream;
-typedef basic_ostream<char, char_traits<char> > ostream;
-typedef basic_ostringstream<char, char_traits<char>, allocator<char> > ostringstream;
-
-} // namespace std
+#include <string>
+#include <iostream>
 
 #endif
 
