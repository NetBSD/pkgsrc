$NetBSD: patch-rewriter_usage__rewriter__test.cc,v 1.1 2020/06/19 05:45:30 taca Exp $

Fix from https://github.com/google/mozc/issues/460

--- rewriter/usage_rewriter_test.cc.orig	2017-11-02 13:32:47.000000000 +0000
+++ rewriter/usage_rewriter_test.cc
@@ -478,7 +478,7 @@ TEST_F(UsageRewriterTest, CommentFromUse
   // Load mock data
   {
     UserDictionaryStorage storage("");
-    UserDictionaryStorage::UserDictionary *dic = storage.add_dictionaries();
+    UserDictionaryStorage::UserDictionary *dic = storage.user_dictionary_storage_base.add_dictionaries();
 
     UserDictionaryStorage::UserDictionaryEntry *entry = dic->add_entries();
     // key="うま", value="アルパカ", comment="アルパカコメント"
@@ -488,7 +488,7 @@ TEST_F(UsageRewriterTest, CommentFromUse
     entry->set_comment("\xE3\x82\xA2\xE3\x83\xAB\xE3\x83\x91\xE3\x82\xAB\xE3"
                        "\x82\xB3\xE3\x83\xA1\xE3\x83\xB3\xE3\x83\x88");
 
-    user_dictionary_->Load(storage);
+    user_dictionary_->Load(storage.user_dictionary_storage_base);
   }
 
   // Emulates the conversion of key="うま".
