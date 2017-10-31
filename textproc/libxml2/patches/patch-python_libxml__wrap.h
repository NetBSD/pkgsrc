$NetBSD: patch-python_libxml__wrap.h,v 1.1 2017/10/31 13:15:44 fhajny Exp $

fix for Python-2.6

--- python/libxml_wrap.h.orig	2014-10-03 09:00:54.000000000 +0000
+++ python/libxml_wrap.h
@@ -28,7 +28,6 @@
  * and don't use Capsule but CObjects
  */
 #if PY_VERSION_HEX < 0x02070000
-#ifndef PyBytes_Check
 #define PyBytes_Check PyString_Check
 #define PyBytes_Size PyString_Size
 #define PyBytes_AsString PyString_AsString
@@ -40,7 +39,6 @@
 #define PyCapsule_CheckExact PyCObject_Check
 #define PyCapsule_GetPointer(o, n) PyCObject_GetDesc((o))
 #endif
-#endif
 
 /**
  * ATTRIBUTE_UNUSED:
