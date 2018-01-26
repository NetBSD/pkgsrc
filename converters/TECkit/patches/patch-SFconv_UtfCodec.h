$NetBSD: patch-SFconv_UtfCodec.h,v 1.1 2018/01/26 16:40:50 jperkin Exp $

Avoid uchar_t redefinition on SunOS.

--- SFconv/UtfCodec.h.orig	2017-06-23 19:39:26.000000000 +0000
+++ SFconv/UtfCodec.h
@@ -34,7 +34,9 @@ using std::int8_t;
 using std::uint8_t;
 using std::ptrdiff_t;
 
+#ifndef __sun
 typedef uint32_t  uchar_t;
+#endif
 
 template <int N>
 struct _utf_codec
