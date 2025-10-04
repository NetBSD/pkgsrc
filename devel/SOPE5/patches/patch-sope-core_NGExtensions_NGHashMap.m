$NetBSD: patch-sope-core_NGExtensions_NGHashMap.m,v 1.1 2025/10/04 14:07:29 kikadf Exp $

* Fix CVE-2025-53603,
  https://github.com/Alinto/sope/commit/e954ab0cd254dc1837af690329b04504410cbe63
* note: remove after 5.12.3 release

--- sope-core/NGExtensions/NGHashMap.m.orig	2022-04-05 15:02:10.000000000 +0000
+++ sope-core/NGExtensions/NGHashMap.m
@@ -216,6 +216,7 @@ static inline unsigned __countObjectsFor
   NSEnumerator *keys    = nil;
   id            key     = nil;
   LList *list    = NULL;
+  LList *root    = NULL;
   LList *newList = NULL;
   LList *oldList = NULL;
 
@@ -223,7 +224,7 @@ static inline unsigned __countObjectsFor
     keys  = [_hashMap keyEnumerator];
     while ((key = [keys nextObject])) {
       list           = [_hashMap __structForKey:key];
-      newList        = initLListElement(list->object,NULL);
+      root = newList = initLListElement(list->object,NULL);
       newList->count = list->count;
       NSMapInsert(self->table,key,newList);
       while (list->next) {
@@ -232,6 +233,7 @@ static inline unsigned __countObjectsFor
         newList       = initLListElement(list->object,NULL);
         oldList->next = newList;
       }
+      root->last = newList;
     }
   }
   return self;
@@ -257,6 +259,7 @@ static inline unsigned __countObjectsFor
       pred       = element;
     }
     root->count = i;
+    root->last  = pred;
     NSMapInsert(self->table,_key, root);
   }
   NSAssert(self->table, @"missing table for hashmap ..");
@@ -712,6 +715,7 @@ static inline unsigned __countObjectsFor
 {
   id            object  = nil;
   LList *root    = NULL;
+  LList *insert  = NULL;
   LList *element = NULL;
   unsigned i = 0;
   
@@ -728,10 +732,13 @@ static inline unsigned __countObjectsFor
     }
 
     root        = initLListElement(_objects[0], NULL);
+    insert = root;
     root->count = _count;
+    // set root->last to last inserted element later
     NSMapInsert(self->table, _key, root);
   }
   else {
+    insert = root;
     if (!(_index < root->count)) {
       [NSException raise:NSRangeException
                   format:@"index %"PRIuPTR" out of range in map 0x%p length %d",
@@ -741,30 +748,38 @@ static inline unsigned __countObjectsFor
     
     root->count += _count;
     if (_index == 0) {
+      // move current data at pos 0 to new element (prepending
+      // a new element would require replacing entry in NSMapTable)
       element         = initLListElement(_objects[0],NULL);
       object          = element->object;
       element->next   = root->next;
       element->object = root->object;      
       root->object    = object;
       root->next      = element;
+      if (root->last == root)
+        root->last = element; // inserted at pos 0 before the only item
     }
     else {
       while (--_index)
-        root = root->next;
+        insert = insert->next;
+      if (root->last == insert)
+        root->last = NULL; // set to last inserted element later
 
       element       = initLListElement(_objects[0], NULL);
-      element->next = root->next;
-      root->next    = element;
-      root          = root->next;
+      element->next = insert->next;
+      insert->next    = element;
+      insert          = insert->next;
     }
   }
   for (i = 1; i < _count; i++) {
     checkForAddErrorMessage(self, _objects[i], _key);
     element       = initLListElement(_objects[i], NULL);
-    element->next = root->next;
-    root->next    = element;
-    root          = element;
+    element->next = insert->next;
+    insert->next    = element;
+    insert          = element;
   }
+  if (root->last == NULL)
+    root->last = insert;
 }
 
 /* adding objects */
@@ -864,6 +879,7 @@ static inline unsigned __countObjectsFor
       root->next   = list->next;
       root->object = list->object;
       root->count--;
+      // cleanup root->last (could be list!) after loop below
       if (list) free(list);
       list = NULL;
     }
@@ -880,6 +896,7 @@ static inline unsigned __countObjectsFor
         list = oldList;
       }
     }
+    root->last = list; // list->next is NULL, i.e. it is the last
     root->count -= cnt;
   }
 }
