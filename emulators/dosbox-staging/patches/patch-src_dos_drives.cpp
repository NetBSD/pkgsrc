$NetBSD: patch-src_dos_drives.cpp,v 1.1 2025/12/14 10:07:19 vins Exp $

Make call to log10 unambiguous.

--- src/dos/drives.cpp.orig	2025-12-14 09:10:59.640371138 +0000
+++ src/dos/drives.cpp
@@ -95,7 +95,7 @@ std::string generate_8x3(const char *lfn
 		input.pop_back();
 	size_t len = 0;
 	auto found = input.rfind('.');
-	unsigned int tilde_pos = 6 - (unsigned int)floor(log10(num));
+	unsigned int tilde_pos = 6 - (unsigned int)floor(log10(static_cast<double>(num)));
 	if (num == 1 || start) {
 		result.clear();
 		len = found != std::string::npos ? found : input.size();
