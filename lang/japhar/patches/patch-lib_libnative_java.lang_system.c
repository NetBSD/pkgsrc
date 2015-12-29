$NetBSD: patch-lib_libnative_java.lang_system.c,v 1.2 2015/12/29 23:34:49 dholland Exp $

Return a value of the correct data type. (in unreachable code, but still)

--- lib/libnative/java.lang/system.c.orig	2013-02-25 20:27:29.000000000 +0000
+++ lib/libnative/java.lang/system.c
@@ -260,7 +260,7 @@ Java_java_lang_System_identityHashCode(J
   if (obj == NULL)
     {
       throw_Exception(env, "java/lang/NullPointerException", NULL);
-      return;
+      return -1;
     }
 
   obj_to_object(obj, jobj);
