$NetBSD: patch-hash.h,v 1.1 2016/10/06 16:27:15 wiz Exp $

Fix: crash handling keywords/labels
https://github.com/neomutt/neomutt/commit/f8160285f285c0bc3c93a2672ea1169af2f04481

--- hash.h.orig	2016-10-03 11:27:32.000000000 +0000
+++ hash.h
@@ -46,6 +46,7 @@ void *hash_find_hash (const HASH * table
 void hash_delete_hash (HASH * table, int hash, const char *key, const void *data,
 		       void (*destroy) (void *));
 void hash_destroy (HASH ** hash, void (*destroy) (void *));
+void hash_set_data (HASH *table, const char *key, void *data);
 
 struct hash_walk_state {
   int index;
