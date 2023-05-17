$NetBSD: patch-src_TagPrint.cxx,v 1.1 2023/05/17 10:45:41 wiz Exp $

Fix build with fmtlib 10. Remove after 0.23.13.

--- src/TagPrint.cxx.orig	2023-01-17 17:54:47.000000000 +0000
+++ src/TagPrint.cxx
@@ -37,7 +37,7 @@ tag_print_types(Response &r) noexcept
 void
 tag_print(Response &r, TagType type, StringView value) noexcept
 {
-	r.Fmt(FMT_STRING("{}: {}\n"), tag_item_names[type], value);
+	r.Fmt(FMT_STRING("{}: {}\n"), tag_item_names[type], std::string(value));
 }
 
 void
