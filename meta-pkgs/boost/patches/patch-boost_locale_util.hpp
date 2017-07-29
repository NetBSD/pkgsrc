$NetBSD: patch-boost_locale_util.hpp,v 1.1 2017/07/29 10:00:03 wiz Exp $

Avoid deprecated auto_ptr.
https://github.com/boostorg/locale/pull/19

--- boost/locale/util.hpp.orig	2017-04-17 02:22:21.000000000 +0000
+++ boost/locale/util.hpp
@@ -176,15 +176,15 @@ namespace util {
     /// This function creates a \a base_converter that can be used for conversion between UTF-8 and
     /// unicode code points
     ///
-    BOOST_LOCALE_DECL std::auto_ptr<base_converter> create_utf8_converter();
+    BOOST_LOCALE_DECL std::unique_ptr<base_converter> create_utf8_converter();
     ///
     /// This function creates a \a base_converter that can be used for conversion between single byte
     /// character encodings like ISO-8859-1, koi8-r, windows-1255 and Unicode code points,
     /// 
     /// If \a encoding is not supported, empty pointer is returned. You should check if
-    /// std::auto_ptr<base_converter>::get() != 0
+    /// std::unique_ptr<base_converter>::get() != 0
     ///
-    BOOST_LOCALE_DECL std::auto_ptr<base_converter> create_simple_converter(std::string const &encoding);
+    BOOST_LOCALE_DECL std::unique_ptr<base_converter> create_simple_converter(std::string const &encoding);
 
 
     ///
@@ -199,7 +199,7 @@ namespace util {
     /// of wide encoding type
     ///
     BOOST_LOCALE_DECL
-    std::locale create_codecvt(std::locale const &in,std::auto_ptr<base_converter> cvt,character_facet_type type);
+    std::locale create_codecvt(std::locale const &in,std::unique_ptr<base_converter> cvt,character_facet_type type);
 
     /// 
     /// Install utf8 codecvt to UTF-16 or UTF-32 into locale \a in and return
