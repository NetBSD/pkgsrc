$NetBSD: patch-src_lib_fmt_ExceptionFormatter.hxx,v 1.2 2024/07/15 10:06:15 adam Exp $

--- src/lib/fmt/ExceptionFormatter.hxx.orig	2023-12-20 07:21:57.000000000 -0800
+++ src/lib/fmt/ExceptionFormatter.hxx	2024-07-14 16:13:04.360506262 -0700
@@ -38,7 +38,7 @@
 struct fmt::formatter<std::exception_ptr> : formatter<string_view>
 {
 	template<typename FormatContext>
-	auto format(std::exception_ptr e, FormatContext &ctx) {
+	auto format(std::exception_ptr e, FormatContext &ctx) const {
 		return formatter<string_view>::format(GetFullMessage(e), ctx);
 	}
 };
