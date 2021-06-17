$NetBSD: patch-mozilla_dom_indexedDB_IDBTransaction.cpp,v 1.1 2021/06/17 11:01:19 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- mozilla/dom/indexedDB/IDBTransaction.cpp.orig	2018-07-09 19:54:35.000000000 +0000
+++ mozilla/dom/indexedDB/IDBTransaction.cpp
@@ -216,7 +216,7 @@ IDBTransaction::Create(JSContext* aCx, I
   MOZ_ASSERT(aMode == READ_ONLY ||
              aMode == READ_WRITE ||
              aMode == READ_WRITE_FLUSH ||
-             aMode == CLEANUP);
+             aMode == TRANSACTION_CLEANUP);
 
   RefPtr<IDBTransaction> transaction =
     new IDBTransaction(aDatabase, aObjectStoreNames, aMode);
@@ -871,7 +871,7 @@ IDBTransaction::GetMode(ErrorResult& aRv
     case READ_WRITE_FLUSH:
       return IDBTransactionMode::Readwriteflush;
 
-    case CLEANUP:
+    case TRANSACTION_CLEANUP:
       return IDBTransactionMode::Cleanup;
 
     case VERSION_CHANGE:
