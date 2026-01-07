$NetBSD: patch-src_zm__image.cpp,v 1.3 2026/01/07 01:03:59 gdt Exp $

--- src/zm_image.cpp.orig	2026-01-07 00:13:06.515742101 +0000
+++ src/zm_image.cpp
@@ -917,7 +917,7 @@ bool Image::ReadRaw(const char *filename
 
   if ( (unsigned int)statbuf.st_size != size ) {
     fclose(infile);
-    Error("Raw file size mismatch, expected %d bytes, found %ld", size, statbuf.st_size);
+    Error("Raw file size mismatch, expected %d bytes, found %jd", size, static_cast<intmax_t>(statbuf.st_size));
     return false;
   }
 
