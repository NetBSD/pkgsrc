$NetBSD: patch-libOpenImageIO_formatspec.cpp,v 1.1 2013/10/14 14:37:30 joerg Exp $

--- libOpenImageIO/formatspec.cpp.orig	2013-10-14 10:55:37.000000000 +0000
+++ libOpenImageIO/formatspec.cpp
@@ -192,7 +192,7 @@ ImageSpec::format_from_quantize (int qua
                quant_max <= std::numeric_limits <int>::max()) {
         return TypeDesc::INT;
     } else if (quant_min >= 0 && 
-               (unsigned int) quant_min >= std::numeric_limits <unsigned int>::min() && 
+               //(unsigned int) quant_min >= std::numeric_limits <unsigned int>::min() && 
                quant_max >= 0 &&
                (unsigned int) quant_max <= std::numeric_limits <unsigned int>::max()) {
         return TypeDesc::UINT;
