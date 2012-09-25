$NetBSD: patch-src_hash_dbr_hash.h,v 1.2 2012/09/25 11:45:11 ryoon Exp $

Fix building with Clang.

--- src/hash/dbr_hash.h.orig	2010-03-25 14:58:07.000000000 +0000
+++ src/hash/dbr_hash.h
@@ -124,7 +124,7 @@ public:
     inline bool remove(KT key)
     {
         struct dbr_hash_slot<KT> *slot;
-        if (! search(key, &slot))
+        if (! this->search(key, &slot))
             return false;
         slot->key = deletedKey;
         int array_slot = slot->array_slot;
@@ -134,7 +134,7 @@ public:
             return true;
         }
         data_array[array_slot] = data_array[--this->count];
-        if (! search(data_array[array_slot], &slot))
+        if (! this->search(data_array[array_slot], &slot))
         {
             log_debug("DBR-Hash-Error: (%d; array_slot=%d; count=%d)\n", data_array[array_slot], array_slot, this->count);
             throw zmm::Exception(_("DBR-Hash-Error: key in data_array not found in hashtable"));
@@ -146,7 +146,7 @@ public:
     inline void put(KT key)
     {
         struct dbr_hash_slot<KT> *slot;
-        if (! search(key, &slot))
+        if (! this->search(key, &slot))
         {
 #ifdef TOMBDEBUG
             if (this->count >= realCapacity)
