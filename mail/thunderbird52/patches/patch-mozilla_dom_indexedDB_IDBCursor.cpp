$NetBSD: patch-mozilla_dom_indexedDB_IDBCursor.cpp,v 1.1 2021/06/17 11:01:19 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- mozilla/dom/indexedDB/IDBCursor.cpp.orig	2018-07-09 19:54:35.000000000 +0000
+++ mozilla/dom/indexedDB/IDBCursor.cpp
@@ -696,7 +696,7 @@ IDBCursor::Update(JSContext* aCx, JS::Ha
     return nullptr;
   }
 
-  if (mTransaction->GetMode() == IDBTransaction::CLEANUP ||
+  if (mTransaction->GetMode() == IDBTransaction::TRANSACTION_CLEANUP ||
       IsSourceDeleted() ||
       !mHaveValue ||
       mType == Type_ObjectStoreKey ||
