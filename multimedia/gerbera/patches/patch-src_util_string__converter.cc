$NetBSD: patch-src_util_string__converter.cc,v 1.1 2022/02/08 06:26:49 khorben Exp $

Fix invalid cast

--- src/util/string_converter.cc.orig	2021-09-30 19:23:27.000000000 +0000
+++ src/util/string_converter.cc
@@ -129,7 +129,7 @@ std::string StringConverter::_convert(co
     ret = iconv(cd, input_ptr, &input_bytes,
         output_ptr, &output_bytes);
 #else
-    ret = iconv(cd, const_cast<char**>(input_ptr), &input_bytes,
+    ret = iconv(cd, const_cast<const char**>(input_ptr), &input_bytes,
         output_ptr, &output_bytes);
 #endif
 
