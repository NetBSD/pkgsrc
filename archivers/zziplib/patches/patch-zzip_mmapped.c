$NetBSD: patch-zzip_mmapped.c,v 1.2 2024/02/28 17:58:00 adam Exp $

Fix clang 15 build with patch from FreeBSD Ports.

--- zzip/mmapped.c.orig	2024-02-28 10:42:45.000000000 +0000
+++ zzip/mmapped.c
@@ -662,7 +662,7 @@ zzip_disk_entry_fopen(ZZIP_DISK * disk,
 
     ___ /* a ZIP64 extended block may follow. */
     size_t csize = zzip_file_header_csize(header);
-    off_t offset = zzip_file_header_to_data(header);
+    size_t offset = zzip_file_header_sizeto_end(header);
     if (csize == 0xFFFFu) {
         struct zzip_extra_zip64* zip64 =
          (struct zzip_extra_zip64*)zzip_file_header_to_extras(header);
@@ -683,7 +683,7 @@ zzip_disk_entry_fopen(ZZIP_DISK * disk,
     file->zlib.zalloc = Z_NULL;
     file->zlib.zfree = Z_NULL;
     file->zlib.avail_in = csize;
-    file->zlib.next_in = offset;
+    file->zlib.next_in = (Bytef *)header + offset;
     ____;
 
     DBG2("compressed size %i", (int) file->zlib.avail_in);
