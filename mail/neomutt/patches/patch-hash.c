$NetBSD: patch-hash.c,v 1.1 2016/10/06 16:27:15 wiz Exp $

Fix: crash handling keywords/labels
https://github.com/neomutt/neomutt/commit/f8160285f285c0bc3c93a2672ea1169af2f04481

--- hash.c.orig	2016-10-03 11:27:32.000000000 +0000
+++ hash.c
@@ -153,6 +153,20 @@ void *hash_find_hash (const HASH * table
   return NULL;
 }
 
+void hash_set_data (HASH *table, const char *key, void *data)
+{
+  if (!table)
+    return;
+
+  unsigned int hash = table->hash_string ((unsigned char *) key, table->nelem);
+
+  struct hash_elem *ptr = table->table[hash];
+  if (!ptr)
+    return;
+
+  ptr->data = data;
+}
+
 void hash_delete_hash (HASH * table, int hash, const char *key, const void *data,
 		       void (*destroy) (void *))
 {
