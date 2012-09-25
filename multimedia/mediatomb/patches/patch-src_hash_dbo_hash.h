$NetBSD: patch-src_hash_dbo_hash.h,v 1.2 2012/09/25 11:45:11 ryoon Exp $

Fix building with Clang.

--- src/hash/dbo_hash.h.orig	2010-03-25 14:58:07.000000000 +0000
+++ src/hash/dbo_hash.h
@@ -106,7 +106,7 @@ public:
     inline bool remove(KT key)
     {
         struct dbo_hash_slot<KT, VT> *slot;
-        if (! search(key, &slot))
+        if (! this->search(key, &slot))
             return false;
         slot->key = deletedKey;
         slot->value->release();
@@ -136,7 +136,7 @@ public:
     inline void put(KT key, zmm::Ref<VT> value)
     {
         struct dbo_hash_slot<KT, VT> *slot;
-        search(key, &slot);
+        this->search(key, &slot);
         put(key, (hash_slot_t)slot, value);
     }
     void put(KT key, hash_slot_t destSlot, zmm::Ref<VT> value)
@@ -162,7 +162,7 @@ public:
     inline zmm::Ref<VT> get(KT key)
     {
         struct dbo_hash_slot<KT, VT> *slot;
-        bool found = search(key, &slot);
+        bool found = this->search(key, &slot);
         if (found)
             return zmm::Ref<VT>(slot->value);
         else
@@ -174,7 +174,7 @@ public:
     inline zmm::Ref<VT> get(KT key, hash_slot_t *destSlot)
     {
         struct dbo_hash_slot<KT, VT> **slot = (struct dbo_hash_slot<KT, VT> **)destSlot;
-        bool found = search(key, slot);
+        bool found = this->search(key, slot);
         if (found)
             return zmm::Ref<VT>((*slot)->value);
         else
