$NetBSD: patch-dictionary_user__dictionary__test.cc,v 1.1 2020/06/19 05:45:30 taca Exp $

Fix from https://github.com/google/mozc/issues/460

--- dictionary/user_dictionary_test.cc.orig	2017-11-02 13:32:47.000000000 +0000
+++ dictionary/user_dictionary_test.cc
@@ -336,9 +336,9 @@ class UserDictionaryTest : public ::test
     std::istringstream is(contents);
     CHECK(is.good());
 
-    storage->Clear();
+    storage->user_dictionary_storage_base.Clear();
     UserDictionaryStorage::UserDictionary *dic
-        = storage->add_dictionaries();
+        = storage->user_dictionary_storage_base.add_dictionaries();
     CHECK(dic);
 
     string line;
@@ -391,7 +391,7 @@ TEST_F(UserDictionaryTest, TestLookupPre
   {
     UserDictionaryStorage storage("");
     UserDictionaryTest::LoadFromString(kUserDictionary0, &storage);
-    dic->Load(storage);
+    dic->Load(storage.user_dictionary_storage_base);
   }
 
   // A normal lookup operation.
@@ -429,7 +429,7 @@ TEST_F(UserDictionaryTest, TestLookupPre
   {
     UserDictionaryStorage storage("");
     LoadFromString(kUserDictionary1, &storage);
-    dic->Load(storage);
+    dic->Load(storage.user_dictionary_storage_base);
   }
 
   // A normal lookup again.
@@ -454,7 +454,7 @@ TEST_F(UserDictionaryTest, TestLookupPre
   {
     UserDictionaryStorage storage("");
     LoadFromString(kUserDictionary0, &storage);
-    dic->Load(storage);
+    dic->Load(storage.user_dictionary_storage_base);
   }
 
   // A normal lookup operation.
@@ -486,7 +486,7 @@ TEST_F(UserDictionaryTest, TestLookupPre
   {
     UserDictionaryStorage storage("");
     LoadFromString(kUserDictionary1, &storage);
-    dic->Load(storage);
+    dic->Load(storage.user_dictionary_storage_base);
   }
 
   // A normal lookup.
@@ -510,7 +510,7 @@ TEST_F(UserDictionaryTest, TestLookupExa
   {
     UserDictionaryStorage storage("");
     LoadFromString(kUserDictionary0, &storage);
-    dic->Load(storage);
+    dic->Load(storage.user_dictionary_storage_base);
   }
 
   // A normal lookup operation.
@@ -547,7 +547,7 @@ TEST_F(UserDictionaryTest, TestLookupExa
     uint64 id = 0;
     EXPECT_TRUE(storage.CreateDictionary("test", &id));
     UserDictionaryStorage::UserDictionary *dic =
-        storage.mutable_dictionaries(0);
+        storage.user_dictionary_storage_base.mutable_dictionaries(0);
 
     // "名詞"
     UserDictionaryStorage::UserDictionaryEntry *entry =
@@ -562,7 +562,7 @@ TEST_F(UserDictionaryTest, TestLookupExa
     entry->set_value("suggest_only");
     entry->set_pos(user_dictionary::UserDictionary::SUGGESTION_ONLY);
 
-    user_dic->Load(storage);
+    user_dic->Load(storage.user_dictionary_storage_base);
   }
 
   // "suggestion_only" should not be looked up.
@@ -584,7 +584,7 @@ TEST_F(UserDictionaryTest, IncognitoMode
   {
     UserDictionaryStorage storage("");
     UserDictionaryTest::LoadFromString(kUserDictionary0, &storage);
-    dic->Load(storage);
+    dic->Load(storage.user_dictionary_storage_base);
   }
 
   TestLookupPrefixHelper(NULL, 0, "start", 4, *dic);
@@ -619,7 +619,7 @@ TEST_F(UserDictionaryTest, AsyncLoadTest
     uint64 id = 0;
     EXPECT_TRUE(storage.CreateDictionary("test", &id));
     UserDictionaryStorage::UserDictionary *dic =
-        storage.mutable_dictionaries(0);
+        storage.user_dictionary_storage_base.mutable_dictionaries(0);
     for (size_t j = 0; j < 10000; ++j) {
       UserDictionaryStorage::UserDictionaryEntry *entry =
           dic->add_entries();
@@ -727,12 +727,12 @@ TEST_F(UserDictionaryTest, AddToAutoRegi
   {
     UserDictionaryStorage storage(filename);
     EXPECT_TRUE(storage.Load());
-    EXPECT_EQ(1, storage.dictionaries_size());
-    EXPECT_EQ(1, storage.dictionaries(0).entries_size());
-    EXPECT_EQ("key", storage.dictionaries(0).entries(0).key());
-    EXPECT_EQ("value", storage.dictionaries(0).entries(0).value());
+    EXPECT_EQ(1, storage.user_dictionary_storage_base.dictionaries_size());
+    EXPECT_EQ(1, storage.user_dictionary_storage_base.dictionaries(0).entries_size());
+    EXPECT_EQ("key", storage.user_dictionary_storage_base.dictionaries(0).entries(0).key());
+    EXPECT_EQ("value", storage.user_dictionary_storage_base.dictionaries(0).entries(0).value());
     EXPECT_EQ(user_dictionary::UserDictionary::NOUN,
-              storage.dictionaries(0).entries(0).pos());
+              storage.user_dictionary_storage_base.dictionaries(0).entries(0).pos());
   }
 }
 
@@ -751,7 +751,7 @@ TEST_F(UserDictionaryTest, TestSuppressi
     uint64 id = 0;
     EXPECT_TRUE(storage.CreateDictionary("test", &id));
     UserDictionaryStorage::UserDictionary *dic =
-        storage.mutable_dictionaries(0);
+        storage.user_dictionary_storage_base.mutable_dictionaries(0);
     for (size_t j = 0; j < 10000; ++j) {
       UserDictionaryStorage::UserDictionaryEntry *entry =
           dic->add_entries();
@@ -775,7 +775,7 @@ TEST_F(UserDictionaryTest, TestSuppressi
 
     suppression_dictionary_->Lock();
     EXPECT_TRUE(suppression_dictionary_->IsLocked());
-    user_dic->Load(storage);
+    user_dic->Load(storage.user_dictionary_storage_base);
     EXPECT_FALSE(suppression_dictionary_->IsLocked());
 
     for (size_t j = 0; j < 10; ++j) {
@@ -787,11 +787,11 @@ TEST_F(UserDictionaryTest, TestSuppressi
 
   // Remove suppression entry
   {
-    storage.Clear();
+    storage.user_dictionary_storage_base.Clear();
     uint64 id = 0;
     EXPECT_TRUE(storage.CreateDictionary("test", &id));
     UserDictionaryStorage::UserDictionary *dic =
-        storage.mutable_dictionaries(0);
+        storage.user_dictionary_storage_base.mutable_dictionaries(0);
     for (size_t j = 0; j < 10000; ++j) {
       UserDictionaryStorage::UserDictionaryEntry *entry =
           dic->add_entries();
@@ -803,7 +803,7 @@ TEST_F(UserDictionaryTest, TestSuppressi
     }
 
     suppression_dictionary_->Lock();
-    user_dic->Load(storage);
+    user_dic->Load(storage.user_dictionary_storage_base);
     EXPECT_FALSE(suppression_dictionary_->IsLocked());
 
     for (size_t j = 0; j < 10; ++j) {
@@ -830,7 +830,7 @@ TEST_F(UserDictionaryTest, TestSuggestio
     uint64 id = 0;
     EXPECT_TRUE(storage.CreateDictionary("test", &id));
     UserDictionaryStorage::UserDictionary *dic =
-        storage.mutable_dictionaries(0);
+        storage.user_dictionary_storage_base.mutable_dictionaries(0);
 
     for (size_t j = 0; j < 10; ++j) {
       UserDictionaryStorage::UserDictionaryEntry *entry =
@@ -850,7 +850,7 @@ TEST_F(UserDictionaryTest, TestSuggestio
       entry->set_pos(user_dictionary::UserDictionary::SUGGESTION_ONLY);
     }
 
-    user_dic->Load(storage);
+    user_dic->Load(storage.user_dictionary_storage_base);
   }
 
   {
@@ -883,7 +883,7 @@ TEST_F(UserDictionaryTest, TestUsageStat
   UserDictionaryStorage storage("");
 
   {
-    UserDictionaryStorage::UserDictionary *dic1 = storage.add_dictionaries();
+    UserDictionaryStorage::UserDictionary *dic1 = storage.user_dictionary_storage_base.add_dictionaries();
     CHECK(dic1);
     UserDictionaryStorage::UserDictionaryEntry *entry;
     entry = dic1->add_entries();
@@ -898,7 +898,7 @@ TEST_F(UserDictionaryTest, TestUsageStat
     entry->set_pos(user_dictionary::UserDictionary::NOUN);
   }
   {
-    UserDictionaryStorage::UserDictionary *dic2 = storage.add_dictionaries();
+    UserDictionaryStorage::UserDictionary *dic2 = storage.user_dictionary_storage_base.add_dictionaries();
     CHECK(dic2);
     UserDictionaryStorage::UserDictionaryEntry *entry;
     entry = dic2->add_entries();
@@ -917,7 +917,7 @@ TEST_F(UserDictionaryTest, TestUsageStat
     entry->set_value("value5");
     entry->set_pos(user_dictionary::UserDictionary::NOUN);
   }
-  dic->Load(storage);
+  dic->Load(storage.user_dictionary_storage_base);
 
   EXPECT_INTEGER_STATS("UserRegisteredWord", 5);
 }
@@ -930,7 +930,7 @@ TEST_F(UserDictionaryTest, LookupComment
   {
     UserDictionaryStorage storage("");
     UserDictionaryTest::LoadFromString(kUserDictionary0, &storage);
-    dic->Load(storage);
+    dic->Load(storage.user_dictionary_storage_base);
   }
 
   // Entry is in user dictionary but has no comment.
