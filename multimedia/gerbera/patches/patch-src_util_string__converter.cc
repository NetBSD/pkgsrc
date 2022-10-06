$NetBSD: patch-src_util_string__converter.cc,v 1.3 2022/10/06 08:41:03 nros Exp $

* fix build on systems that have const in second argument to iconv

--- src/util/string_converter.cc.orig	2022-10-06 08:09:22.564707578 +0000
+++ src/util/string_converter.cc
@@ -122,8 +122,8 @@ std::string StringConverter::_convert(co
     // log_debug(("iconv: BEFORE: input bytes left: {}  output bytes left: {}",
     //        input_bytes, output_bytes));
 #if defined(ICONV_CONST) || defined(SOLARIS)
-    int ret = iconv(cd, inputPtr, &input_bytes,
-        output_ptr, &output_bytes);
+    int ret = iconv(cd, inputPtr, &inputBytes,
+        outputPtr, &outputBytes);
 #else
     int ret = iconv(cd, const_cast<char**>(inputPtr), &inputBytes,
         outputPtr, &outputBytes);
