$NetBSD: patch-lib_utils_mu-html-to-text.cc,v 1.1 2026/05/13 17:46:13 ktnb Exp $

ctype(3) for NetBSD 11

--- lib/utils/mu-html-to-text.cc.orig	2026-05-13 17:22:59.975533319 +0000
+++ lib/utils/mu-html-to-text.cc
@@ -36,7 +36,7 @@ starts_with(std::string_view haystack, std::string_vie
 		return false;
 
 	for (auto&& c = 0U; c != needle.size(); ++c)
-		if (::tolower(haystack[c]) != ::tolower(needle[c]))
+		if (::tolower((unsigned char)haystack[c]) != ::tolower((unsigned char)needle[c]))
 			return false;
 
 	return true;
@@ -440,7 +440,7 @@ html_escape_char(Context& ctx)
 	auto unescape=[escs](std::string_view esc)->char {
 		if (esc.empty())
 			return ' ';
-		auto first{static_cast<char>(::tolower(esc.at(0)))};
+		auto first{static_cast<char>(::tolower((unsigned char)esc.at(0)))};
 		auto rest=esc.substr(1);
 		if (seq_some(escs, [&](auto&& e){return starts_with(rest, e);}))
 			return first;
