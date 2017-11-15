$NetBSD: patch-common.h,v 1.1 2017/11/15 18:22:22 he Exp $

Ensure we adhere to valid value domain for isxxxx() function/macro.

--- common.h.orig	2017-11-10 11:21:21.000000000 +0000
+++ common.h
@@ -86,7 +86,7 @@ int is_integer(const char *str)
 
   while(*str)
   {
-    if (!isdigit(*str))
+    if (!isdigit((unsigned char)*str))
       return FALSE;
     str++;
   }
@@ -114,7 +114,7 @@ int is_float(const char *str)
 
       has_dot = TRUE;
     }
-    else if (!isdigit(*str))
+    else if (!isdigit((unsigned char)*str))
     {
       return FALSE;
     }
@@ -125,4 +125,4 @@ int is_float(const char *str)
   return has_dot; // to be float must contain a dot
 }
 
-#endif
\ No newline at end of file
+#endif
