$NetBSD: patch-dictionary_user__dictionary.cc,v 1.1 2020/06/19 05:45:30 taca Exp $

Fix from https://github.com/google/mozc/issues/460

--- dictionary/user_dictionary.cc.orig	2017-11-02 13:32:47.000000000 +0000
+++ dictionary/user_dictionary.cc
@@ -289,7 +289,7 @@ class UserDictionary::UserDictionaryRelo
     }
 
     auto_register_mode_ = false;
-    dic_->Load(*(storage.get()));
+    dic_->Load(storage.get()->user_dictionary_storage_base);
   }
 
  private:
