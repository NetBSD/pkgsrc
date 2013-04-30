$NetBSD: patch-src_McHashTable.h,v 1.1 2013/04/30 22:16:12 joerg Exp $

--- src/McHashTable.h.orig	2013-04-30 19:49:36.000000000 +0000
+++ src/McHashTable.h
@@ -113,7 +113,7 @@ public:
     /// Returns pointer to associated value if key does exist, 0 otherwise.
     Value* lookup(const Key& key)
 	{
-	Item* item = bucketList[hash(key) & mask];
+	Item* item = bucketList[::hash(key) & mask];
 	while(item)
 	    {
 	    if(compare(item->key, key) == 0)
@@ -191,7 +191,7 @@ McHashTable<Key,Value>::~McHashTable()
 template<class Key, class Value>
 int McHashTable<Key,Value>::insert(const Key& key, const Value& value)
 {
-    int i = hash(key) & mask;
+    int i = ::hash(key) & mask;
     Item* item = bucketList[i];
 
     while(item)
@@ -217,7 +217,7 @@ int McHashTable<Key,Value>::insert(const
 template<class Key, class Value>
 Value* McHashTable<Key,Value>::insert(const Key& key)
 {
-    int i = hash(key) & mask;
+    int i = ::hash(key) & mask;
     Item *item = bucketList[i];
 
     while(item)
@@ -240,7 +240,7 @@ Value* McHashTable<Key,Value>::insert(co
 template<class Key, class Value>
 int McHashTable<Key,Value>::remove(const Key& key)
 {
-    int i = hash(key) & mask;
+    int i = ::hash(key) & mask;
     Item* item = bucketList[i];
 
     if(item == 0)
@@ -283,7 +283,7 @@ void McHashTable<Key,Value>::rebuildTabl
 	Item *item = oldList[i];
 	while(item)
 	    {
-	    int k = hash(item->key) & mask;
+	    int k = ::hash(item->key) & mask;
 	    Item* next = bucketList[k];
 	    Item* oldNext = item->next;
 	    bucketList[k] = item;
