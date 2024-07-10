$NetBSD: patch-example_example.cpp,v 1.1 2024/07/10 20:50:57 wiz Exp $

https://github.com/gabime/spdlog/commit/d276069a6e916b1e1fd45885b15b72bd8ee000a7

--- example/example.cpp.orig	2024-07-10 20:49:42.716094450 +0000
+++ example/example.cpp
@@ -272,7 +272,7 @@ struct my_type {
 #ifndef SPDLOG_USE_STD_FORMAT  // when using fmtlib
 template <>
 struct fmt::formatter<my_type> : fmt::formatter<std::string> {
-    auto format(my_type my, format_context &ctx) -> decltype(ctx.out()) {
+    auto format(my_type my, format_context &ctx) const -> decltype(ctx.out()) {
         return fmt::format_to(ctx.out(), "[my_type i={}]", my.i);
     }
 };
