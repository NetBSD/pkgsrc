$NetBSD: patch-lib_utils_mu-html-to-text.cc,v 1.2 2026/05/13 19:12:43 ktnb Exp $

ctype(3) for NetBSD 11

--- lib/utils/mu-html-to-text.cc.orig	2026-04-27 19:03:29.000000000 +0000
+++ lib/utils/mu-html-to-text.cc
@@ -36,7 +36,7 @@ starts_with(std::string_view haystack, std::string_vie
 		return false;
 
 	for (auto&& c = 0U; c != needle.size(); ++c)
-		if (::tolower(haystack[c]) != ::tolower(needle[c]))
+		if (::tolower((unsigned char)haystack[c]) != ::tolower((unsigned char)needle[c]))
 			return false;
 
 	return true;
@@ -143,7 +143,7 @@ class Context { (public)
 	std::string_view eat_head_word() {
 		size_t start_pos{pos_};
 		while (!done()) {
-			if (!::isalpha(html_.at(pos_)))
+			if (!::isalpha(static_cast<unsigned char>(html_.at(pos_))))
 				break;
 			++pos_;
 		}
@@ -440,7 +440,7 @@ html_escape_char(Context& ctx)
 	auto unescape=[escs](std::string_view esc)->char {
 		if (esc.empty())
 			return ' ';
-		auto first{static_cast<char>(::tolower(esc.at(0)))};
+		auto first{static_cast<char>(::tolower((unsigned char)esc.at(0)))};
 		auto rest=esc.substr(1);
 		if (seq_some(escs, [&](auto&& e){return starts_with(rest, e);}))
 			return first;
