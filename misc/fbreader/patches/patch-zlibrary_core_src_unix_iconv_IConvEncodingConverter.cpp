$NetBSD: patch-zlibrary_core_src_unix_iconv_IConvEncodingConverter.cpp,v 1.1 2019/10/29 14:09:09 kamil Exp $

Handle NetBSD POSIX iconv(3) switch.

--- zlibrary/core/src/unix/iconv/IConvEncodingConverter.cpp.orig	2012-11-30 12:41:25.000000000 +0000
+++ zlibrary/core/src/unix/iconv/IConvEncodingConverter.cpp
@@ -23,6 +23,13 @@
 
 #include "IConvEncodingConverter.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if !__NetBSD_Prereq__(9,99,17)
+#define DO_ICONV_CAST 1
+#endif
+#endif
+
 class IConvEncodingConverter : public ZLEncodingConverter {
 
 private:
