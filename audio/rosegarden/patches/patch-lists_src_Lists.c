$NetBSD: patch-lists_src_Lists.c,v 1.1 2022/01/01 09:20:41 dholland Exp $

Silence compiler warnings.
Avoid UB:
  - declare a suitable return type for a function returning a truth value
  - source files must end with a newline

--- lists/src/Lists.c~	2002-03-22 22:24:07.000000000 +0000
+++ lists/src/Lists.c
@@ -218,7 +218,7 @@ List LIST_Split(List a)
 
 // ***
 /* Check if given element is a part of list chunk */
-List LIST_IsWithin (List who, List start, List end)
+int LIST_IsWithin (List who, List start, List end)
 {
   Begin ("LIST_IsWithin");
   
@@ -234,4 +234,4 @@ List LIST_IsWithin (List who, List start
   
   Return (0);
 }
-// *** Deemus
\ No newline at end of file
+// *** Deemus
