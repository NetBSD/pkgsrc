$NetBSD: patch-src_sort.c,v 1.1 2025/05/28 09:21:25 wiz Exp $

sort: fix buffer under-read (CWE-127)
* src/sort.c (begfield): Check pointer adjustment
to avoid Out-of-range pointer offset (CWE-823).
(limfield): Likewise.
Fixes https://bugs.gnu.org/78507

https://cgit.git.savannah.gnu.org/cgit/coreutils.git/commit/?id=8c9602e3a145e9596dc1a63c6ed67865814b6633

--- src/sort.c.orig	2025-01-16 17:30:02.000000000 +0000
+++ src/sort.c
@@ -1645,7 +1645,11 @@ begfield (struct line const *line, struc
       ++ptr;
 
   /* Advance PTR by SCHAR (if possible), but no further than LIM.  */
-  ptr = MIN (lim, ptr + schar);
+  size_t remaining_bytes = lim - ptr;
+  if (schar < remaining_bytes)
+    ptr += schar;
+  else
+    ptr = lim;
 
   return ptr;
 }
@@ -1747,7 +1751,11 @@ limfield (struct line const *line, struc
           ++ptr;
 
       /* Advance PTR by ECHAR (if possible), but no further than LIM.  */
-      ptr = MIN (lim, ptr + echar);
+      size_t remaining_bytes = lim - ptr;
+      if (echar < remaining_bytes)
+        ptr += echar;
+      else
+        ptr = lim;
     }
 
   return ptr;
