$NetBSD: patch-libyara_libyara.c,v 1.1 2019/12/14 10:46:08 khorben Exp $

Ensure we adhere to valid value domain for isxxxx() function/macro.

--- libyara/libyara.c.orig	2019-10-10 11:10:50.000000000 +0000
+++ libyara/libyara.c
@@ -138,7 +138,7 @@ YR_API int yr_initialize(void)
     else
       yr_altercase[i] = i;
 
-    yr_lowercase[i] = tolower(i);
+    yr_lowercase[i] = tolower((unsigned char)i);
   }
 
   FAIL_ON_ERROR(yr_heap_alloc());
