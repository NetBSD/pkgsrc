$NetBSD: patch-xpcom_glue_nsTPtrArray.h,v 1.1 2012/11/18 01:55:52 joerg Exp $

--- xpcom/glue/nsTPtrArray.h.orig	2012-11-17 16:59:07.000000000 +0000
+++ xpcom/glue/nsTPtrArray.h
@@ -64,7 +64,7 @@ class nsTPtrArray : public nsTArray<E*> 
 
     // Initialize this array and pre-allocate some number of elements.
     explicit nsTPtrArray(size_type capacity) {
-      SetCapacity(capacity);
+      this->SetCapacity(capacity);
     }
     
     // The array's copy-constructor performs a 'deep' copy of the given array.
