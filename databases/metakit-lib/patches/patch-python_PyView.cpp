$NetBSD: patch-python_PyView.cpp,v 1.1 2012/11/16 00:40:44 joerg Exp $

--- python/PyView.cpp.orig	2012-11-15 14:50:12.000000000 +0000
+++ python/PyView.cpp
@@ -631,19 +631,19 @@ static PyObject *PyView_access(PyView *o
     }
 
     PyObject *buffer = PyString_FromStringAndSize(0, length);
-    int o = 0;
+    int o2 = 0;
 
-    while (o < length) {
-      c4_Bytes buf = prop(row).Access(offset + o, length - o);
+    while (o2 < length) {
+      c4_Bytes buf = prop(row).Access(offset + o2, length - o2);
       int n = buf.Size();
       if (n == 0)
         break;
-      memcpy(PyString_AS_STRING(buffer) + o, buf.Contents(), n);
-      o += n;
+      memcpy(PyString_AS_STRING(buffer) + o2, buf.Contents(), n);
+      o2 += n;
     }
 
-    if (o < length)
-      _PyString_Resize(&buffer, o);
+    if (o2 < length)
+      _PyString_Resize(&buffer, o2);
 
     return buffer;
   } catch (...) {
