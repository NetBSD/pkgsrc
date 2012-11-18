$NetBSD: patch-xpcom_glue_nsRefPtrHashtable.h,v 1.1 2012/11/18 01:55:52 joerg Exp $

--- xpcom/glue/nsRefPtrHashtable.h.orig	2012-03-06 14:45:48.000000000 +0000
+++ xpcom/glue/nsRefPtrHashtable.h
@@ -112,7 +112,7 @@ nsRefPtrHashtable<KeyClass,RefPtr>::Get
   (KeyType aKey, UserDataType* pRefPtr) const
 {
   typename nsBaseHashtable<KeyClass, nsRefPtr<RefPtr>, RefPtr*>::EntryType* ent =
-    GetEntry(aKey);
+    this->GetEntry(aKey);
 
   if (ent)
   {
@@ -140,7 +140,7 @@ nsRefPtrHashtable<KeyClass,RefPtr>::GetW
   (KeyType aKey, PRBool* aFound) const
 {
   typename nsBaseHashtable<KeyClass, nsRefPtr<RefPtr>, RefPtr*>::EntryType* ent =
-    GetEntry(aKey);
+    this->GetEntry(aKey);
 
   if (ent)
   {
@@ -168,7 +168,7 @@ nsRefPtrHashtableMT<KeyClass,RefPtr>::Ge
   PR_Lock(this->mLock);
 
   typename nsBaseHashtableMT<KeyClass, nsRefPtr<RefPtr>, RefPtr*>::EntryType* ent =
-    GetEntry(aKey);
+    this->GetEntry(aKey);
 
   if (ent)
   {
