$NetBSD: patch-src_compression_zziplib_generic_fseeko.cpp,v 1.1 2012/01/11 19:01:48 hans Exp $

Don't jump over variable initialization.

--- src/compression/zziplib/generic/fseeko.cpp.orig	2008-01-05 18:33:45.000000000 +0100
+++ src/compression/zziplib/generic/fseeko.cpp	2011-12-30 16:11:43.327510421 +0100
@@ -445,6 +445,7 @@ struct zzip_entry_file /* : zzip_file_he
 zzip__new__ ZZIP_ENTRY_FILE*
 zzip_entry_fopen (ZZIP_ENTRY* entry, int takeover)
 {
+    ___ zzip_off_t seek;
     if (! entry) return 0;
     if (! takeover) {
 	ZZIP_ENTRY* found = (ZZIP_ENTRY*)malloc (sizeof(*entry));
@@ -472,7 +473,7 @@ zzip_entry_fopen (ZZIP_ENTRY* entry, int
     file->zlib.zalloc = Z_NULL;
     file->zlib.zfree = Z_NULL;
 
-    ___ zzip_off_t seek = file->data;
+    seek = file->data;
     seek += sizeof(file->buffer); seek -= seek & (sizeof(file->buffer)-1);
     assert (file->data < seek); /* pre-read to next PAGESIZE boundary... */
     fseeko (file->entry->diskfile, file->data + file->dataoff, SEEK_SET);
