$NetBSD: patch-dictionary_user__dictionary__storage__test.cc,v 1.1 2020/06/19 05:45:30 taca Exp $

Fix from https://github.com/google/mozc/issues/460

--- dictionary/user_dictionary_storage_test.cc.orig	2017-11-02 13:32:47.000000000 +0000
+++ dictionary/user_dictionary_storage_test.cc
@@ -135,7 +135,7 @@ TEST_F(UserDictionaryStorageTest, BasicO
   }
 
   for (size_t i = 0; i < kDictionariesSize; ++i) {
-    EXPECT_EQ(storage.mutable_dictionaries(i + dict_size),
+    EXPECT_EQ(storage.user_dictionary_storage_base.mutable_dictionaries(i + dict_size),
               storage.GetUserDictionary(id[i]));
     EXPECT_EQ(NULL, storage.GetUserDictionary(id[i] + 1));
   }
@@ -167,7 +167,7 @@ TEST_F(UserDictionaryStorageTest, BasicO
   EXPECT_FALSE(storage.DeleteDictionary(0));
 
   EXPECT_TRUE(storage.DeleteDictionary(id[1]));
-  EXPECT_EQ(kDictionariesSize + dict_size - 1, storage.dictionaries_size());
+  EXPECT_EQ(kDictionariesSize + dict_size - 1, storage.user_dictionary_storage_base.dictionaries_size());
 }
 
 TEST_F(UserDictionaryStorageTest, DeleteTest) {
@@ -176,7 +176,7 @@ TEST_F(UserDictionaryStorageTest, Delete
 
   // repeat 10 times
   for (int i = 0; i < 10; ++i) {
-    storage.Clear();
+    storage.user_dictionary_storage_base.Clear();
     std::vector<uint64> ids(100);
     for (size_t i = 0; i < ids.size(); ++i) {
       EXPECT_TRUE(storage.CreateDictionary(
@@ -193,10 +193,10 @@ TEST_F(UserDictionaryStorageTest, Delete
       alive.push_back(ids[i]);
     }
 
-    EXPECT_EQ(alive.size(), storage.dictionaries_size());
+    EXPECT_EQ(alive.size(), storage.user_dictionary_storage_base.dictionaries_size());
 
     for (size_t i = 0; i < alive.size(); ++i) {
-      EXPECT_EQ(alive[i], storage.dictionaries(i).id());
+      EXPECT_EQ(alive[i], storage.user_dictionary_storage_base.dictionaries(i).id());
     }
   }
 }
@@ -270,7 +270,7 @@ TEST_F(UserDictionaryStorageTest, Serial
         const size_t entry_size = Util::Random(100) + 1;
         for (size_t j = 0; j < entry_size; ++j) {
           UserDictionaryStorage::UserDictionary *dic =
-              storage1.mutable_dictionaries(i);
+              storage1.user_dictionary_storage_base.mutable_dictionaries(i);
           UserDictionaryStorage::UserDictionaryEntry *entry =
               dic->add_entries();
           entry->set_key(GenRandomString(10));
@@ -290,7 +290,7 @@ TEST_F(UserDictionaryStorageTest, Serial
       EXPECT_TRUE(storage2.Load());
     }
 
-    EXPECT_EQ(storage1.DebugString(), storage2.DebugString());
+    EXPECT_EQ(storage1.user_dictionary_storage_base.DebugString(), storage2.user_dictionary_storage_base.DebugString());
   }
 }
 
@@ -354,7 +354,7 @@ TEST_F(UserDictionaryStorageTest, Conver
     uint64 dict_id = 0;
     ASSERT_TRUE(storage.CreateDictionary(data.dictionary_name, &dict_id));
     UserDictionaryStorage::UserDictionary *dict =
-        storage.mutable_dictionaries(storage.GetUserDictionaryIndex(dict_id));
+        storage.user_dictionary_storage_base.mutable_dictionaries(storage.GetUserDictionaryIndex(dict_id));
     dict->set_syncable(data.is_sync_dictionary);
     dict->set_removed(data.is_removed_dictionary);
     if (data.has_normal_entry) {
@@ -371,7 +371,7 @@ TEST_F(UserDictionaryStorageTest, Conver
       entry->set_removed(true);
     }
   }
-  EXPECT_EQ(9, UserDictionaryStorage::CountSyncableDictionaries(storage));
+  EXPECT_EQ(9, UserDictionaryStorage::CountSyncableDictionaries(storage.user_dictionary_storage_base));
 
   ASSERT_TRUE(storage.ConvertSyncDictionariesToNormalDictionaries());
 
@@ -389,12 +389,12 @@ TEST_F(UserDictionaryStorageTest, Conver
     { true, kDictionaryNameConvertedFromSyncableDictionary },
   };
 
-  EXPECT_EQ(0, UserDictionaryStorage::CountSyncableDictionaries(storage));
-  ASSERT_EQ(arraysize(expected_data), storage.dictionaries_size());
+  EXPECT_EQ(0, UserDictionaryStorage::CountSyncableDictionaries(storage.user_dictionary_storage_base));
+  ASSERT_EQ(arraysize(expected_data), storage.user_dictionary_storage_base.dictionaries_size());
   for (size_t i = 0; i < arraysize(expected_data); ++i) {
     SCOPED_TRACE(Util::StringPrintf("verify %d", static_cast<int>(i)));
     const ExpectedData &expected = expected_data[i];
-    const UserDictionaryStorage::UserDictionary &dict = storage.dictionaries(i);
+    const UserDictionaryStorage::UserDictionary &dict = storage.user_dictionary_storage_base.dictionaries(i);
 
     EXPECT_EQ(expected.dictionary_name, dict.name());
     EXPECT_FALSE(dict.syncable());
@@ -408,42 +408,42 @@ TEST_F(UserDictionaryStorageTest, Conver
   }
 
   // Test duplicated dictionary name.
-  storage.Clear();
+  storage.user_dictionary_storage_base.Clear();
   {
     uint64 dict_id = 0;
     storage.CreateDictionary(
         UserDictionaryStorage::default_sync_dictionary_name(), &dict_id);
     storage.CreateDictionary(
         kDictionaryNameConvertedFromSyncableDictionary, &dict_id);
-    ASSERT_EQ(2, storage.dictionaries_size());
+    ASSERT_EQ(2, storage.user_dictionary_storage_base.dictionaries_size());
     UserDictionaryStorage::UserDictionary *dict;
-    dict = storage.mutable_dictionaries(0);
+    dict = storage.user_dictionary_storage_base.mutable_dictionaries(0);
     dict->set_syncable(true);
     dict->add_entries()->set_key("0");
-    dict = storage.mutable_dictionaries(1);
+    dict = storage.user_dictionary_storage_base.mutable_dictionaries(1);
     dict->set_syncable(false);
     dict->add_entries()->set_key("1");
   }
   ASSERT_TRUE(storage.ConvertSyncDictionariesToNormalDictionaries());
-  EXPECT_EQ(0, UserDictionaryStorage::CountSyncableDictionaries(storage));
-  EXPECT_EQ(2, storage.dictionaries_size());
+  EXPECT_EQ(0, UserDictionaryStorage::CountSyncableDictionaries(storage.user_dictionary_storage_base));
+  EXPECT_EQ(2, storage.user_dictionary_storage_base.dictionaries_size());
   EXPECT_EQ(Util::StringPrintf("%s_1",
                                kDictionaryNameConvertedFromSyncableDictionary),
-            storage.dictionaries(0).name());
+            storage.user_dictionary_storage_base.dictionaries(0).name());
   EXPECT_EQ(kDictionaryNameConvertedFromSyncableDictionary,
-            storage.dictionaries(1).name());
+            storage.user_dictionary_storage_base.dictionaries(1).name());
 }
 
 TEST_F(UserDictionaryStorageTest, AddToAutoRegisteredDictionary) {
   {
     UserDictionaryStorage storage(GetUserDictionaryFile());
-    EXPECT_EQ(0, storage.dictionaries_size());
+    EXPECT_EQ(0, storage.user_dictionary_storage_base.dictionaries_size());
     EXPECT_TRUE(storage.AddToAutoRegisteredDictionary(
         "key1", "value1", UserDictionary::NOUN));
-    EXPECT_EQ(1, storage.dictionaries_size());
-    EXPECT_EQ(1, storage.dictionaries(0).entries_size());
+    EXPECT_EQ(1, storage.user_dictionary_storage_base.dictionaries_size());
+    EXPECT_EQ(1, storage.user_dictionary_storage_base.dictionaries(0).entries_size());
     const UserDictionaryStorage::UserDictionaryEntry &entry1 =
-        storage.dictionaries(0).entries(0);
+        storage.user_dictionary_storage_base.dictionaries(0).entries(0);
     EXPECT_EQ("key1", entry1.key());
     EXPECT_EQ("value1", entry1.value());
     EXPECT_EQ(UserDictionary::NOUN, entry1.pos());
@@ -451,10 +451,10 @@ TEST_F(UserDictionaryStorageTest, AddToA
 
     EXPECT_TRUE(storage.AddToAutoRegisteredDictionary(
         "key2", "value2", UserDictionary::NOUN));
-    EXPECT_EQ(1, storage.dictionaries_size());
-    EXPECT_EQ(2, storage.dictionaries(0).entries_size());
+    EXPECT_EQ(1, storage.user_dictionary_storage_base.dictionaries_size());
+    EXPECT_EQ(2, storage.user_dictionary_storage_base.dictionaries(0).entries_size());
     const UserDictionaryStorage::UserDictionaryEntry &entry2 =
-        storage.dictionaries(0).entries(1);
+        storage.user_dictionary_storage_base.dictionaries(0).entries(1);
     EXPECT_EQ("key2", entry2.key());
     EXPECT_EQ("value2", entry2.value());
     EXPECT_EQ(UserDictionary::NOUN, entry2.pos());
@@ -478,7 +478,7 @@ TEST_F(UserDictionaryStorageTest, Export
   {
     UserDictionaryStorage storage(GetUserDictionaryFile());
     {
-      UserDictionary *dictionary = storage.add_dictionaries();
+      UserDictionary *dictionary = storage.user_dictionary_storage_base.add_dictionaries();
       dictionary->set_id(kDummyDictionaryId);
       UserDictionary::Entry *entry = dictionary->add_entries();
       entry->set_key("key");
