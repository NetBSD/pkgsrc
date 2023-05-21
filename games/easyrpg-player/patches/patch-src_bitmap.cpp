$NetBSD: patch-src_bitmap.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/bitmap.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/bitmap.cpp
@@ -96,7 +96,7 @@ Bitmap::Bitmap(Filesystem_Stream::InputS
 	pixman_format = find_format(format);
 
 	if (!stream) {
-		Output::Error("Couldn't read image file {}", stream.GetName());
+		Output::Error("Couldn't read image file {}", std::string(stream.GetName()));
 		return;
 	}
 
@@ -117,7 +117,7 @@ Bitmap::Bitmap(Filesystem_Stream::InputS
 	else if (bytes >= 4 && strncmp((char*)(data + 1), "PNG", 3) == 0)
 		img_okay = ImagePNG::ReadPNG(stream, transparent, w, h, pixels);
 	else
-		Output::Warning("Unsupported image file {} (Magic: {:02X})", stream.GetName(), *reinterpret_cast<uint32_t*>(data));
+		Output::Warning("Unsupported image file {} (Magic: {:02X})", std::string(stream.GetName()), *reinterpret_cast<uint32_t*>(data));
 
 	if (!img_okay) {
 		free(pixels);
