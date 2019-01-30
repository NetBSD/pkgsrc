$NetBSD: patch-src_hb-dsalgs.hh,v 1.1 2019/01/30 19:21:22 jperkin Exp $

Fix build on SunOS where int8_t is not explicitly "signed".

--- src/hb-dsalgs.hh.orig	2018-12-20 03:27:58.000000000 +0000
+++ src/hb-dsalgs.hh
@@ -297,6 +297,9 @@ hb_ceil_to_4 (unsigned int v)
 }
 
 template <typename T> struct hb_is_signed;
+#if defined(__sun) && defined(_CHAR_IS_SIGNED)
+template <> struct hb_is_signed<int8_t> { enum { value = true }; };
+#endif
 template <> struct hb_is_signed<signed char> { enum { value = true }; };
 template <> struct hb_is_signed<signed short> { enum { value = true }; };
 template <> struct hb_is_signed<signed int> { enum { value = true }; };
