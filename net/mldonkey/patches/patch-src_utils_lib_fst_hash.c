$NetBSD: patch-src_utils_lib_fst_hash.c,v 1.1 2016/08/15 15:48:19 jaapb Exp $

Compile with OCaml 4.03
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
