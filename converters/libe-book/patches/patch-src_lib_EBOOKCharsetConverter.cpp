$NetBSD: patch-src_lib_EBOOKCharsetConverter.cpp,v 1.1 2020/11/05 09:19:22 ryoon Exp $

* Fix build with textproc/icu-68.1.

--- src/lib/EBOOKCharsetConverter.cpp.orig	2018-01-01 11:16:28.000000000 +0000
+++ src/lib/EBOOKCharsetConverter.cpp
@@ -124,7 +124,7 @@ bool EBOOKCharsetConverter::convertBytes
       m_converterToUTF8.get(), m_converterToUnicode.get(),
       &outText, outText + out.size(), &inText, inText + length,
       nullptr, nullptr, nullptr, nullptr,
-      TRUE, TRUE, &status)
+      true, true, &status)
     ;
     if (status==U_BUFFER_OVERFLOW_ERROR)
     {
