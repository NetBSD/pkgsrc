$NetBSD: patch-src_hash_dso_hash.h,v 1.2 2012/09/25 11:45:11 ryoon Exp $

Fix building with Clang.

--- src/hash/dso_hash.h.orig	2010-03-25 14:58:07.000000000 +0000
+++ src/hash/dso_hash.h
@@ -100,7 +100,7 @@ public:
     inline bool remove(zmm::String key)
     {
         struct dso_hash_slot<VT> *slot;
-        if (! search(key, &slot))
+        if (! this->search(key, &slot))
             return false;
         slot->key->release();
         slot->value->release();
@@ -112,7 +112,7 @@ public:
     inline void put(zmm::String key, zmm::Ref<VT> value)
     {
         struct dso_hash_slot<VT> *slot;
-        search(key, &slot);
+        this->search(key, &slot);
         put(key, (hash_slot_t)slot, value);
     }
     void put(zmm::String key, hash_slot_t destSlot, zmm::Ref<VT> value)
@@ -141,7 +141,7 @@ public:
     inline zmm::Ref<VT> get(zmm::String key)
     {
         struct dso_hash_slot<VT> *slot;
-        bool found = search(key, &slot);
+        bool found = this->search(key, &slot);
         if (found)
             return zmm::Ref<VT>(slot->value);
         else
@@ -153,7 +153,7 @@ public:
     inline zmm::Ref<VT> get(zmm::String key, hash_slot_t *destSlot)
     {
         struct dso_hash_slot<VT> **slot = (struct dso_hash_slot<VT> **)destSlot;
-        bool found = search(key, slot);
+        bool found = this->search(key, slot);
         if (found)
             return zmm::Ref<VT>((*slot)->value);
         else
