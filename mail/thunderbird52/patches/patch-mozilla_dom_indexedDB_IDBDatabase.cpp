$NetBSD: patch-mozilla_dom_indexedDB_IDBDatabase.cpp,v 1.1 2021/06/17 11:01:19 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- mozilla/dom/indexedDB/IDBDatabase.cpp.orig	2018-07-09 19:54:35.000000000 +0000
+++ mozilla/dom/indexedDB/IDBDatabase.cpp
@@ -668,7 +668,7 @@ IDBDatabase::Transaction(JSContext* aCx,
       break;
     case IDBTransactionMode::Readwrite:
       if (mQuotaExceeded) {
-        mode = IDBTransaction::CLEANUP;
+        mode = IDBTransaction::TRANSACTION_CLEANUP;
         mQuotaExceeded = false;
       } else {
         mode = IDBTransaction::READ_WRITE;
@@ -678,7 +678,7 @@ IDBDatabase::Transaction(JSContext* aCx,
       mode = IDBTransaction::READ_WRITE_FLUSH;
       break;
     case IDBTransactionMode::Cleanup:
-      mode = IDBTransaction::CLEANUP;
+      mode = IDBTransaction::TRANSACTION_CLEANUP;
       mQuotaExceeded = false;
       break;
     case IDBTransactionMode::Versionchange:
@@ -713,7 +713,7 @@ IDBDatabase::Transaction(JSContext* aCx,
 
   transaction->SetBackgroundActor(actor);
 
-  if (mode == IDBTransaction::CLEANUP) {
+  if (mode == IDBTransaction::TRANSACTION_CLEANUP) {
     ExpireFileActors(/* aExpireAll */ true);
   }
 
@@ -863,7 +863,7 @@ IDBDatabase::AbortTransactions(bool aSho
             // We warn for any transactions that could have written data.
             case IDBTransaction::READ_WRITE:
             case IDBTransaction::READ_WRITE_FLUSH:
-            case IDBTransaction::CLEANUP:
+            case IDBTransaction::TRANSACTION_CLEANUP:
             case IDBTransaction::VERSION_CHANGE:
               transactionsThatNeedWarning.AppendElement(transaction);
               break;
