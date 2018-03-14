$NetBSD: patch-src_utils_lib_fst_hash.c,v 1.2 2018/03/14 14:05:37 dholland Exp $

Compile with OCaml 4.03 (int64 -> int64_t)
and with 4.06 (string -> bytes)

--- src/utils/lib/fst_hash.c.orig	2005-12-10 19:44:28.000000000 +0000
+++ src/utils/lib/fst_hash.c
@@ -197,7 +197,7 @@ unsigned short fst_hash_checksum (unsign
 /*****************************************************************************/
 
 // hash file
-int fst_hash_file (unsigned char *fth, char *file, int64 filesize)
+int fst_hash_file (unsigned char *fth, char *file, int64_t filesize)
 {
   FILE *fp;
   unsigned char *buf;
@@ -271,7 +271,7 @@ int fst_hash_file (unsigned char *fth, c
 }
 
 
-void fst_hash_string (unsigned char *fth, unsigned char *file, int64 filesize)
+void fst_hash_string (unsigned char *fth, unsigned char *file, int64_t filesize)
 {
   unsigned char * buf = file;
   size_t len = filesize;
@@ -323,14 +323,14 @@ void fst_hash_string (unsigned char *fth
 
 value fst_hash_file_ml(value digest, value filename, value filesize)
 {
-  if(fst_hash_file(String_val(digest), String_val(filename), 
+  if(fst_hash_file(bytes_val(digest), String_val(filename), 
         Int64_val(filesize))) return Val_unit;
   failwith("Exception during FST computation");
 }
 
 value fst_hash_string_ml(value digest, value s, value size)
 {
-  fst_hash_string(String_val(digest), String_val(s), Int_val(size));
+  fst_hash_string(Bytes_val(digest), String_val(s), Int_val(size));
   return Val_unit;
 }
 
