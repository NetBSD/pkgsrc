$NetBSD: patch-src_utils_lib_tiger.c,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/lib/tiger.c~	2012-06-24 07:59:41.000000000 +0000
+++ src/utils/lib/tiger.c
@@ -827,7 +827,7 @@ OFF_T tiger_block_size(OFF_T len)
 
 value tigertree_unsafe_string(value digest_v, value string_v, value len_v)
 {
-  unsigned char *digest = String_val(digest_v);
+  unsigned char *digest = Bytes_val(digest_v);
   unsigned char *string = String_val(string_v);
   long len = Long_val(len_v);
 
@@ -838,7 +838,7 @@ value tigertree_unsafe_string(value dige
 
 value tiger_unsafe_string(value digest_v, value string_v, value len_v)
 {
-  unsigned char *digest = String_val(digest_v);
+  unsigned char *digest = Bytes_val(digest_v);
   unsigned char *string = String_val(string_v);
   long len = Long_val(len_v);
 
