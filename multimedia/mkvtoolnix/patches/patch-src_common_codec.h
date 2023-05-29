$NetBSD: patch-src_common_codec.h,v 1.1 2023/05/29 19:51:25 wiz Exp $

Fix build with fmtlib 10.
https://gitlab.com/mbunkus/mkvtoolnix/-/commit/24716ce95bf5b10d685611de23489045cf2ca5cc

--- src/common/codec.h.orig	2023-04-30 10:27:25.000000000 +0000
+++ src/common/codec.h
@@ -231,3 +231,7 @@ operator <<(std::ostream &out,
 
   return out;
 }
+
+#if FMT_VERSION >= 90000
+template <> struct fmt::formatter<codec_c> : ostream_formatter {};
+#endif  // FMT_VERSION >= 90000
