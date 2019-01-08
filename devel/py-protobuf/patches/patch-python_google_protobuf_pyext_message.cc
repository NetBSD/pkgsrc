$NetBSD: patch-python_google_protobuf_pyext_message.cc,v 1.1 2019/01/08 05:56:19 markd Exp $

--- python/google/protobuf/pyext/message.cc.orig	2018-07-30 22:16:10.000000000 +0000
+++ python/google/protobuf/pyext/message.cc
@@ -79,7 +79,7 @@
     (PyUnicode_Check(ob)? PyUnicode_AsUTF8(ob): PyBytes_AsString(ob))
   #define PyString_AsStringAndSize(ob, charpp, sizep) \
     (PyUnicode_Check(ob)? \
-       ((*(charpp) = PyUnicode_AsUTF8AndSize(ob, (sizep))) == NULL? -1: 0): \
+       ((*(charpp) = const_cast<char*>(PyUnicode_AsUTF8AndSize(ob, (sizep)))) == NULL? -1: 0): \
        PyBytes_AsStringAndSize(ob, (charpp), (sizep)))
   #endif
 #endif
@@ -1529,7 +1529,7 @@ PyObject* HasField(CMessage* self, PyObj
     return NULL;
   }
 #else
-  field_name = PyUnicode_AsUTF8AndSize(arg, &size);
+  field_name = const_cast<char*>(PyUnicode_AsUTF8AndSize(arg, &size));
   if (!field_name) {
     return NULL;
   }
