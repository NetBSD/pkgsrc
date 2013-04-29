$NetBSD: patch-sql_password.c,v 1.1 2013/04/29 21:16:57 joerg Exp $

--- sql/password.c.orig	2013-04-28 13:53:48.000000000 +0000
+++ sql/password.c
@@ -545,7 +545,7 @@ check_scramble_sha1(const uchar *scrambl
   /* now buf supposedly contains hash_stage1: so we can get hash_stage2 */
   compute_sha1_hash(hash_stage2_reassured, (const char *) buf, SHA1_HASH_SIZE);
 
-  return test(memcmp(hash_stage2, hash_stage2_reassured, SHA1_HASH_SIZE));
+  return my_test(memcmp(hash_stage2, hash_stage2_reassured, SHA1_HASH_SIZE));
 }
 
 my_bool
