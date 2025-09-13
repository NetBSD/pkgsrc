$NetBSD: patch-src_io_resource_ResourcePath.cpp,v 1.1 2025/09/13 21:52:04 nia Exp $

Fix ctype usage on invalid ascii sequences.

--- src/io/resource/ResourcePath.cpp.orig	2025-09-13 21:47:28.611514282 +0000
+++ src/io/resource/ResourcePath.cpp
@@ -348,7 +348,7 @@ path path::load(const std::string & str)
 		}
 		
 		for(size_t p = start; p < pos; p++) {
-			copy[ostart++] = std::tolower(str[p]);
+			copy[ostart++] = std::tolower((unsigned char)str[p]);
 		}
 		
 	}
