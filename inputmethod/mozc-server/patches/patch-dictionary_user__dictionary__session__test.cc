$NetBSD: patch-dictionary_user__dictionary__session__test.cc,v 1.1 2020/06/19 05:45:30 taca Exp $

Fix from https://github.com/google/mozc/issues/460

--- dictionary/user_dictionary_session_test.cc.orig	2017-11-02 13:32:47.000000000 +0000
+++ dictionary/user_dictionary_session_test.cc
@@ -105,12 +105,12 @@ TEST_F(UserDictionarySessionTest, SaveAn
 
   ASSERT_EQ(UserDictionaryCommandStatus::FILE_NOT_FOUND, session.Load());
 
-  session.mutable_storage()->set_version(10);
+  session.mutable_storage()->user_dictionary_storage_base.set_version(10);
   ASSERT_EQ(UserDictionaryCommandStatus::USER_DICTIONARY_COMMAND_SUCCESS,
             session.Save());
 
   // Clear once, in order to make sure that Load is actually working.
-  session.mutable_storage()->Clear();
+  session.mutable_storage()->user_dictionary_storage_base.Clear();
   ASSERT_EQ(UserDictionaryCommandStatus::USER_DICTIONARY_COMMAND_SUCCESS,
             session.Load());
 
@@ -140,7 +140,7 @@ TEST_F(UserDictionarySessionTest, DISABL
 
   // Create huge dummy data.
   {
-    UserDictionaryStorage *storage = session.mutable_storage();
+    UserDictionaryStorage *storage = &session.mutable_storage()->user_dictionary_storage_base;
     for (int i = 0; i < 100; ++i) {
       UserDictionary *dictionary = storage->add_dictionaries();
       for (int j = 0; j < 1000; ++j) {
@@ -157,7 +157,7 @@ TEST_F(UserDictionarySessionTest, DISABL
   ASSERT_EQ(UserDictionaryCommandStatus::FILE_SIZE_LIMIT_EXCEEDED,
             session.Save());
 
-  session.mutable_storage()->Clear();
+  session.mutable_storage()->user_dictionary_storage_base.Clear();
   ASSERT_EQ(UserDictionaryCommandStatus::USER_DICTIONARY_COMMAND_SUCCESS,
             session.Load());
 
@@ -201,7 +201,7 @@ TEST_F(UserDictionarySessionTest, Create
 
   while (session.storage().dictionaries_size() <
          ::mozc::UserDictionaryStorage::max_dictionary_size()) {
-    session.mutable_storage()->add_dictionaries();
+    session.mutable_storage()->user_dictionary_storage_base.add_dictionaries();
   }
   EXPECT_EQ(UserDictionaryCommandStatus::DICTIONARY_SIZE_LIMIT_EXCEEDED,
             session.CreateDictionary("dictionary 2", &dummy_dictionary_id));
@@ -214,7 +214,7 @@ TEST_F(UserDictionarySessionTest, Delete
   const uint64 kDummyId = 10;
   {
     UserDictionary *user_dictionary =
-        session.mutable_storage()->add_dictionaries();
+        session.mutable_storage()->user_dictionary_storage_base.add_dictionaries();
     user_dictionary->set_id(kDummyId);
   }
 
@@ -239,7 +239,7 @@ TEST_F(UserDictionarySessionTest,
   const uint64 kDummyId = 10;
   {
     UserDictionary *user_dictionary =
-        session.mutable_storage()->add_dictionaries();
+        session.mutable_storage()->user_dictionary_storage_base.add_dictionaries();
     user_dictionary->set_id(kDummyId);
   }
 
