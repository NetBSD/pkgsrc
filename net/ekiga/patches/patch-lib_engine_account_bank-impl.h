$NetBSD: patch-lib_engine_account_bank-impl.h,v 1.1 2013/03/28 21:34:51 joerg Exp $

--- lib/engine/account/bank-impl.h.orig	2013-03-28 17:43:20.000000000 +0000
+++ lib/engine/account/bank-impl.h
@@ -212,7 +212,7 @@ template<typename AccountType>
 void
 Ekiga::BankImpl<AccountType>::add_account (gmref_ptr<AccountType> account)
 {
-  add_object (account);
+  this->add_object (account);
 
   account->questions.add_handler (questions.make_slot ());
   account->registration_event.connect (sigc::bind (sigc::mem_fun (this, &Ekiga::BankImpl<AccountType>::on_registration_event), account));
