$NetBSD: patch-common_ulist.c,v 1.1 2016/12/04 04:11:33 ryoon Exp $

--- common/ulist.c.orig	2016-06-15 18:58:17.000000000 +0000
+++ common/ulist.c
@@ -29,7 +29,6 @@ struct UList {
     UListNode *tail;
     
     int32_t size;
-    int32_t currentIndex;
 };
 
 static void ulist_addFirstItem(UList *list, UListNode *newItem);
@@ -51,7 +50,6 @@ U_CAPI UList *U_EXPORT2 ulist_createEmpt
     newList->head = NULL;
     newList->tail = NULL;
     newList->size = 0;
-    newList->currentIndex = -1;
     
     return newList;
 }
@@ -80,8 +78,9 @@ static void ulist_removeItem(UList *list
     } else {
         p->next->previous = p->previous;
     }
-    list->curr = NULL;
-    list->currentIndex = 0;
+    if (p == list->curr) {
+        list->curr = p->next;
+    }
     --list->size;
     if (p->forceDelete) {
         uprv_free(p->data);
@@ -150,7 +149,6 @@ U_CAPI void U_EXPORT2 ulist_addItemBegin
         newItem->next = list->head;
         list->head->previous = newItem;
         list->head = newItem;
-        list->currentIndex++;
     }
     
     list->size++;
@@ -193,7 +191,6 @@ U_CAPI void *U_EXPORT2 ulist_getNext(ULi
     
     curr = list->curr;
     list->curr = curr->next;
-    list->currentIndex++;
     
     return curr->data;
 }
@@ -209,7 +206,6 @@ U_CAPI int32_t U_EXPORT2 ulist_getListSi
 U_CAPI void U_EXPORT2 ulist_resetList(UList *list) {
     if (list != NULL) {
         list->curr = list->head;
-        list->currentIndex = 0;
     }
 }
 
@@ -272,4 +268,3 @@ U_CAPI void U_EXPORT2 ulist_reset_keywor
 U_CAPI UList * U_EXPORT2 ulist_getListFromEnum(UEnumeration *en) {
     return (UList *)(en->context);
 }
-
