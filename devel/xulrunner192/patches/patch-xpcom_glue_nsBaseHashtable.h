$NetBSD: patch-xpcom_glue_nsBaseHashtable.h,v 1.1 2012/11/18 01:55:52 joerg Exp $

--- xpcom/glue/nsBaseHashtable.h.orig	2012-11-17 15:46:20.000000000 +0000
+++ xpcom/glue/nsBaseHashtable.h
@@ -123,7 +123,7 @@ public:
    */
   PRBool Get(KeyType aKey, UserDataType* pData NS_OUTPARAM) const
   {
-    EntryType* ent = GetEntry(aKey);
+    EntryType* ent = this->GetEntry(aKey);
 
     if (!ent)
       return PR_FALSE;
@@ -142,7 +142,7 @@ public:
    */
   PRBool Put(KeyType aKey, UserDataType aData)
   {
-    EntryType* ent = PutEntry(aKey);
+    EntryType* ent = this->PutEntry(aKey);
 
     if (!ent)
       return PR_FALSE;
@@ -156,7 +156,7 @@ public:
    * remove the data for the associated key
    * @param aKey the key to remove from the hashtable
    */
-  void Remove(KeyType aKey) { RemoveEntry(aKey); }
+  void Remove(KeyType aKey) { this->RemoveEntry(aKey); }
 
   /**
    * function type provided by the application for enumeration.
