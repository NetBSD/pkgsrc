$NetBSD: patch-store_transaction.cpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- store/transaction.cpp.orig	2013-05-06 08:17:59.000000000 +0000
+++ store/transaction.cpp
@@ -437,7 +437,7 @@ struct store::results_iterator::impl {
 ///
 /// \param pimpl_ The internal implementation details of the iterator.
 store::results_iterator::results_iterator(
-    std::tr1::shared_ptr< impl > pimpl_) :
+    shared_ptr< impl > pimpl_) :
     _pimpl(pimpl_)
 {
 }
@@ -680,7 +680,7 @@ store::results_iterator
 store::transaction::get_action_results(const int64_t action_id)
 {
     try {
-        return results_iterator(std::tr1::shared_ptr< results_iterator::impl >(
+        return results_iterator(shared_ptr< results_iterator::impl >(
            new results_iterator::impl(_pimpl->_backend, action_id)));
     } catch (const sqlite::error& e) {
         throw error(e.what());
