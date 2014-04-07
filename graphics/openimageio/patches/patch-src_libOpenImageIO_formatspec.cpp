$NetBSD: patch-src_libOpenImageIO_formatspec.cpp,v 1.1 2014/04/07 12:15:55 ryoon Exp $

--- src/libOpenImageIO/formatspec.cpp.orig	2014-04-03 06:08:57.000000000 +0000
+++ src/libOpenImageIO/formatspec.cpp
@@ -192,7 +192,7 @@ ImageSpec::format_from_quantize (int qua
                quant_max <= std::numeric_limits <int>::max()) {
         return TypeDesc::INT;
     } else if (quant_min >= 0 && 
-               (unsigned int) quant_min >= std::numeric_limits <unsigned int>::min() && 
+               //(unsigned int) quant_min >= std::numeric_limits <unsigned int>::min() && 
                quant_max >= 0 &&
                (unsigned int) quant_max <= std::numeric_limits <unsigned int>::max()) {
         return TypeDesc::UINT;
