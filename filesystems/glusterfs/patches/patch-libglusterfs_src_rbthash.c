$NetBSD: patch-libglusterfs_src_rbthash.c,v 1.1 2012/12/20 21:53:20 joerg Exp $

--- libglusterfs/src/rbthash.c.orig	2012-12-20 15:00:05.000000000 +0000
+++ libglusterfs/src/rbthash.c
@@ -228,7 +228,7 @@ rbthash_deinit_entry (rbthash_table_t *t
 }
 
 
-inline struct rbthash_bucket *
+struct rbthash_bucket *
 rbthash_entry_bucket (rbthash_table_t *tbl, rbthash_entry_t * entry)
 {
         int     nbucket = 0;
@@ -302,7 +302,7 @@ err:
         return ret;
 }
 
-inline struct rbthash_bucket *
+struct rbthash_bucket *
 rbthash_key_bucket (rbthash_table_t *tbl, void *key, int keylen)
 {
         uint32_t        keyhash = 0;
