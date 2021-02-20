$NetBSD: patch-src_rime_gear_memory.cc,v 1.1 2021/02/20 20:53:01 ryoon Exp $

fix(memory): possibly dereferencing null pointer 
From: https://github.com/rime/librime/commit/1c2644de2b026972dd80a3770b92d7194d523303

--- src/rime/gear/memory.cc
+++ src/rime/gear/memory.cc
@@ -68,10 +68,10 @@ Memory::Memory(const Ticket& ticket) {
 
   // user dictionary is named after language; dictionary name may have an
   // optional suffix separated from the language component by dot.
-  language_.reset(new Language{
-    user_dict_ ? user_dict_->name() :
-    Language::get_language_component(dict_->name())
-  });
+  language_.reset(
+      user_dict_ ? new Language{user_dict_->name()} :
+      dict_ ? new Language{Language::get_language_component(dict_->name())} :
+      nullptr);
 
   Context* ctx = ticket.engine->context();
   commit_connection_ = ctx->commit_notifier().connect(
