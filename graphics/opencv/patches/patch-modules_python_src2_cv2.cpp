$NetBSD: patch-modules_python_src2_cv2.cpp,v 1.1 2018/09/26 19:33:50 prlw1 Exp $

Sprinkle const for python 3.7 compatibility

--- modules/python/src2/cv2.cpp.orig	2018-02-23 08:38:33.000000000 +0000
+++ modules/python/src2/cv2.cpp
@@ -886,7 +886,7 @@ bool pyopencv_to(PyObject* obj, String& 
     (void)name;
     if(!obj || obj == Py_None)
         return true;
-    char* str = PyString_AsString(obj);
+    const char* str = PyString_AsString(obj);
     if(!str)
         return false;
     value = String(str);
