$NetBSD: patch-src_database_sql__format.h,v 1.1 2022/10/10 12:47:51 adam Exp $

https://github.com/gerbera/gerbera/pull/2694

--- src/database/sql_format.h.orig	2022-05-03 17:39:25.000000000 +0000
+++ src/database/sql_format.h
@@ -42,7 +42,7 @@ struct SQLIdentifier {
 template <>
 struct fmt::formatter<SQLIdentifier> : formatter<std::string_view> {
     template <typename FormatContext>
-    auto format(const SQLIdentifier& tn, FormatContext& ctx) -> decltype(ctx.out())
+    auto format(const SQLIdentifier& tn, FormatContext& ctx) const -> decltype(ctx.out())
     {
         return format_to(ctx.out(), "{}{}{}", tn.quote_begin, tn.name, tn.quote_end);
     }
@@ -61,7 +61,7 @@ struct ColumnUpdate {
 template <>
 struct fmt::formatter<ColumnUpdate> : formatter<std::string_view> {
     template <typename FormatContext>
-    auto format(const ColumnUpdate& a, FormatContext& ctx) -> decltype(ctx.out())
+    auto format(const ColumnUpdate& a, FormatContext& ctx) const -> decltype(ctx.out())
     {
         return format_to(ctx.out(), "{} = {}", a.column, a.value);
     }
