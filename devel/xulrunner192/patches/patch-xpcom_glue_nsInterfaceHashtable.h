$NetBSD: patch-xpcom_glue_nsInterfaceHashtable.h,v 1.1 2012/11/18 01:55:52 joerg Exp $

--- xpcom/glue/nsInterfaceHashtable.h.orig	2012-11-17 15:51:37.000000000 +0000
+++ xpcom/glue/nsInterfaceHashtable.h
@@ -111,7 +111,7 @@ nsInterfaceHashtable<KeyClass,Interface>
   (KeyType aKey, UserDataType* pInterface) const
 {
   typename nsBaseHashtable<KeyClass, nsCOMPtr<Interface>, Interface*>::EntryType* ent =
-    GetEntry(aKey);
+    this->GetEntry(aKey);
 
   if (ent)
   {
@@ -139,7 +139,7 @@ nsInterfaceHashtable<KeyClass,Interface>
   (KeyType aKey, PRBool* aFound) const
 {
   typename nsBaseHashtable<KeyClass, nsCOMPtr<Interface>, Interface*>::EntryType* ent =
-    GetEntry(aKey);
+    this->GetEntry(aKey);
 
   if (ent)
   {
