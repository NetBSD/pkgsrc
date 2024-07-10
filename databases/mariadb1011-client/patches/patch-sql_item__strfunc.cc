$NetBSD: patch-sql_item__strfunc.cc,v 1.1 2024/07/10 21:11:03 wiz Exp $

Fix build with fmtlib 11.

--- sql/item_strfunc.cc.orig	2024-07-10 21:07:27.206529082 +0000
+++ sql/item_strfunc.cc
@@ -1382,7 +1382,7 @@ bool Item_func_sformat::fix_length_and_d
 namespace fmt {
   template <> struct formatter<String>: formatter<string_view> {
     template <typename FormatContext>
-    auto format(String c, FormatContext& ctx) -> decltype(ctx.out()) {
+    auto format(String c, FormatContext& ctx) const -> decltype(ctx.out()) {
       string_view name = { c.ptr(), c.length() };
       return formatter<string_view>::format(name, ctx);
     };
