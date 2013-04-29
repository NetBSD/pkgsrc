$NetBSD: patch-mysys_my__getwd.c,v 1.1 2013/04/29 21:16:56 joerg Exp $

--- mysys/my_getwd.c.orig	2013-04-28 13:52:00.000000000 +0000
+++ mysys/my_getwd.c
@@ -162,12 +162,12 @@ int test_if_hard_path(register const cha
 
 my_bool has_path(const char *name)
 {
-  return test(strchr(name, FN_LIBCHAR)) 
+  return my_test(strchr(name, FN_LIBCHAR)) 
 #if FN_LIBCHAR != '/'
-    || test(strchr(name,'/'))
+    || my_test(strchr(name,'/'))
 #endif
 #ifdef FN_DEVCHAR
-    || test(strchr(name, FN_DEVCHAR))
+    || my_test(strchr(name, FN_DEVCHAR))
 #endif
     ;
 }
