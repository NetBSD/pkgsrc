$NetBSD: patch-src_io_resource_PakReader.cpp,v 1.1 2025/09/13 21:52:04 nia Exp $

Fix ctype usage on invalid ascii sequences.

--- src/io/resource/PakReader.cpp.orig	2025-09-13 21:47:39.414391494 +0000
+++ src/io/resource/PakReader.cpp
@@ -555,7 +555,9 @@ bool PakReader::addArchive(const fs::pat
 			}
 			
 			size_t len = std::strlen(filename);
-			std::transform(filename, filename + len, filename, ::tolower);
+			for(size_t i = 0; i < len; ++i) {
+				filename[i] = ::tolower((unsigned char)filename[i]);
+			}
 			
 			u32 offset;
 			u32 flags;
