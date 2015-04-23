$NetBSD: patch-lib_boost_utf8__codecvt__facet_utf8__codecvt__facet.cpp,v 1.1 2015/04/23 18:28:57 joerg Exp $

--- lib/boost/utf8_codecvt_facet/utf8_codecvt_facet.cpp.orig	2011-10-09 09:48:12.000000000 +0000
+++ lib/boost/utf8_codecvt_facet/utf8_codecvt_facet.cpp
@@ -171,7 +171,7 @@ std::codecvt_base::result utf8_codecvt_f
 // How many char objects can I process to get <= max_limit
 // wchar_t objects?
 int utf8_codecvt_facet::do_length(
-    BOOST_CODECVT_DO_LENGTH_CONST std::mbstate_t &,
+    const std::mbstate_t &,
     const char * from,
     const char * from_end, 
     std::size_t max_limit
