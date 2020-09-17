$NetBSD: patch-lib_string.cpp,v 1.7 2020/09/17 14:48:08 wiz Exp $

Explicitly use std::wcsnrtombs.

https://trac.filezilla-project.org/ticket/12280

--- lib/string.cpp.orig	2020-07-07 12:06:31.000000000 +0000
+++ lib/string.cpp
@@ -354,7 +354,7 @@ std::string to_string(std::wstring_view
 
 			std::mbstate_t ps{};
 			wchar_t const* in_p = in.data() + start;
-			size_t len = wcsnrtombs(nullptr, &in_p, inlen, 0, &ps);
+			size_t len = std::wcsnrtombs(nullptr, &in_p, inlen, 0, &ps);
 			if (len != static_cast<size_t>(-1)) {
 				size_t old = ret.size();
 				if (start) {
@@ -364,7 +364,7 @@ std::string to_string(std::wstring_view
 				char* out_p = &ret[old];
 
 				in_p = in.data() + start; // Some implementations of wcsrtombs change src even on null dst
-				wcsnrtombs(out_p, &in_p, inlen, len, &ps);
+				std::wcsnrtombs(out_p, &in_p, inlen, len, &ps);
 			}
 			else {
 				ret.clear();
