$NetBSD: patch-src_lib_fmt_PathFormatter.hxx,v 1.2 2024/07/15 10:06:15 adam Exp $

--- src/lib/fmt/PathFormatter.hxx.orig	2023-12-20 07:21:57.000000000 -0800
+++ src/lib/fmt/PathFormatter.hxx	2024-07-14 16:14:38.192993397 -0700
@@ -29,7 +29,7 @@
 struct fmt::formatter<Path> : formatter<string_view>
 {
 	template<typename FormatContext>
-	auto format(Path path, FormatContext &ctx) {
+	auto format(Path path, FormatContext &ctx) const {
 		return formatter<string_view>::format(path.ToUTF8(), ctx);
 	}
 };
