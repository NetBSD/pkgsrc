$NetBSD: patch-src_include_uri.h,v 1.1 2017/08/25 20:04:07 joerg Exp $

Moved to libfilezilla.

--- src/include/uri.h.orig	2017-08-25 16:23:33.414154308 +0000
+++ src/include/uri.h
@@ -47,12 +47,6 @@ private:
 	bool parse_authority(std::string && authority);
 };
 
-std::string percent_encode(std::string const& s, bool keep_slashes = false);
-std::string percent_encode(std::wstring const& s, bool keep_slashes = false);
-std::wstring percent_encode_w(std::wstring const& s, bool keep_slashes = false);
-
-std::string percent_decode(std::string const& s);
-
 }
 
 #endif
