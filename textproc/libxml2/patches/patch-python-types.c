$NetBSD: patch-python-types.c,v 1.1 2020/11/08 23:31:44 js Exp $

Fix compilation with Python 3.9.

--- python/types.c.orig	2019-10-22 18:46:01.000000000 +0000
+++ python/types.c
@@ -602,16 +602,16 @@ libxml_xmlXPathObjectPtrConvert(PyObject
     if (obj == NULL) {
         return (NULL);
     }
-    if PyFloat_Check (obj) {
+    if (PyFloat_Check (obj)) {
         ret = xmlXPathNewFloat((double) PyFloat_AS_DOUBLE(obj));
-    } else if PyLong_Check(obj) {
+    } else if (PyLong_Check(obj)) {
 #ifdef PyLong_AS_LONG
         ret = xmlXPathNewFloat((double) PyLong_AS_LONG(obj));
 #else
         ret = xmlXPathNewFloat((double) PyInt_AS_LONG(obj));
 #endif
 #ifdef PyBool_Check
-    } else if PyBool_Check (obj) {
+    } else if (PyBool_Check (obj)) {
 
         if (obj == Py_True) {
           ret = xmlXPathNewBoolean(1);
@@ -620,14 +620,14 @@ libxml_xmlXPathObjectPtrConvert(PyObject
           ret = xmlXPathNewBoolean(0);
         }
 #endif
-    } else if PyBytes_Check (obj) {
+    } else if (PyBytes_Check (obj)) {
         xmlChar *str;
 
         str = xmlStrndup((const xmlChar *) PyBytes_AS_STRING(obj),
                          PyBytes_GET_SIZE(obj));
         ret = xmlXPathWrapString(str);
 #ifdef PyUnicode_Check
-    } else if PyUnicode_Check (obj) {
+    } else if (PyUnicode_Check (obj)) {
 #if PY_VERSION_HEX >= 0x03030000
         xmlChar *str;
 	const char *tmp;
@@ -650,7 +650,7 @@ libxml_xmlXPathObjectPtrConvert(PyObject
 	ret = xmlXPathWrapString(str);
 #endif
 #endif
-    } else if PyList_Check (obj) {
+    } else if (PyList_Check (obj)) {
         int i;
         PyObject *node;
         xmlNodePtr cur;
