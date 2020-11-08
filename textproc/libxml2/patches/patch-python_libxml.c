$NetBSD: patch-python_libxml.c,v 1.2 2020/11/08 23:31:44 js Exp $

Avoid returning invalid UTF-8 strings to python.
Based on https://bugzilla.opensuse.org/attachment.cgi?id=746044&action=edit
Fixes https://github.com/itstool/itstool/issues/22
Fix compilation with Python 3.9.

--- python/libxml.c.orig	2019-10-22 18:46:01.000000000 +0000
+++ python/libxml.c
@@ -294,7 +294,7 @@ xmlPythonFileReadRaw (void * context, ch
 	lenread = PyBytes_Size(ret);
 	data = PyBytes_AsString(ret);
 #ifdef PyUnicode_Check
-    } else if PyUnicode_Check (ret) {
+    } else if (PyUnicode_Check (ret)) {
 #if PY_VERSION_HEX >= 0x03030000
         Py_ssize_t size;
 	const char *tmp;
@@ -359,7 +359,7 @@ xmlPythonFileRead (void * context, char 
 	lenread = PyBytes_Size(ret);
 	data = PyBytes_AsString(ret);
 #ifdef PyUnicode_Check
-    } else if PyUnicode_Check (ret) {
+    } else if (PyUnicode_Check (ret)) {
 #if PY_VERSION_HEX >= 0x03030000
         Py_ssize_t size;
 	const char *tmp;
@@ -1620,6 +1620,7 @@ libxml_xmlErrorFuncHandler(ATTRIBUTE_UNU
     PyObject *message;
     PyObject *result;
     char str[1000];
+    unsigned char *ptr = (unsigned char *)str;
 
 #ifdef DEBUG_ERROR
     printf("libxml_xmlErrorFuncHandler(%p, %s, ...) called\n", ctx, msg);
@@ -1636,10 +1637,14 @@ libxml_xmlErrorFuncHandler(ATTRIBUTE_UNU
 	    str[999] = 0;
         va_end(ap);
 
+        /* Ensure the error string doesn't start at UTF8 continuation. */
+        while (*ptr && (*ptr & 0xc0) == 0x80)
+	    ptr++;
+
         list = PyTuple_New(2);
         PyTuple_SetItem(list, 0, libxml_xmlPythonErrorFuncCtxt);
         Py_XINCREF(libxml_xmlPythonErrorFuncCtxt);
-        message = libxml_charPtrConstWrap(str);
+        message = libxml_charPtrConstWrap(ptr);
         PyTuple_SetItem(list, 1, message);
         result = PyEval_CallObject(libxml_xmlPythonErrorFuncHandler, list);
         Py_XDECREF(list);
