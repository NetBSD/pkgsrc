$NetBSD: patch-pandas___libs_src_ujson_python_objToJSON.c,v 1.1 2020/08/09 19:11:32 joerg Exp $

Fix build with NumPy 1.19.

--- pandas/_libs/src/ujson/python/objToJSON.c.orig	2019-10-31 20:16:52.000000000 +0000
+++ pandas/_libs/src/ujson/python/objToJSON.c
@@ -178,7 +178,7 @@ void *initObjToJSON(void)
 
     /* Initialise numpy API and use 2/3 compatible return */
     import_array();
-    return NUMPY_IMPORT_ARRAY_RETVAL;
+    return NULL;
 }
 
 static TypeContext *createTypeContext(void) {
