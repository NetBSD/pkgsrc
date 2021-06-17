$NetBSD: patch-mozilla_dom_indexedDB_IDBObjectStore.cpp,v 1.1 2021/06/17 11:01:19 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- mozilla/dom/indexedDB/IDBObjectStore.cpp.orig	2018-07-09 19:54:35.000000000 +0000
+++ mozilla/dom/indexedDB/IDBObjectStore.cpp
@@ -1406,7 +1406,7 @@ IDBObjectStore::AddOrPut(JSContext* aCx,
   MOZ_ASSERT(aCx);
   MOZ_ASSERT_IF(aFromCursor, aOverwrite);
 
-  if (mTransaction->GetMode() == IDBTransaction::CLEANUP ||
+  if (mTransaction->GetMode() == IDBTransaction::TRANSACTION_CLEANUP ||
       mDeletedSpec) {
     aRv.Throw(NS_ERROR_DOM_INDEXEDDB_NOT_ALLOWED_ERR);
     return nullptr;
