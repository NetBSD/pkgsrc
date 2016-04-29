$NetBSD: patch-lib_string.cpp,v 1.1 2016/04/29 11:54:06 wiz Exp $

Fix build on NetBSD with iconv's second argument being const char **.

--- lib/string.cpp.orig	2016-04-15 07:52:15.000000000 +0000
+++ lib/string.cpp
@@ -111,7 +111,7 @@ std::wstring to_wstring_from_utf8(std::s
 			char* out_buf = new char[out_len];
 			char* out_p = out_buf;
 
-			size_t r = iconv(cd, &in_p, &in_len, &out_p, &out_len);
+			size_t r = iconv(cd, (const char **)&in_p, &in_len, &out_p, &out_len);
 
 			if (r != static_cast<size_t>(-1)) {
 				ret.assign(reinterpret_cast<wchar_t*>(out_buf), reinterpret_cast<wchar_t*>(out_p));
@@ -175,7 +175,7 @@ std::string FZ_PUBLIC_SYMBOL to_utf8(std
 			char* out_buf = new char[out_len];
 			char* out_p = out_buf;
 
-			size_t r = iconv(cd, &in_p, &in_len, &out_p, &out_len);
+			size_t r = iconv(cd, (const char **)&in_p, &in_len, &out_p, &out_len);
 
 			if (r != static_cast<size_t>(-1)) {
 				ret.assign(out_buf, out_p);
