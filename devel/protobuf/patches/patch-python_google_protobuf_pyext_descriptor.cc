$NetBSD: patch-python_google_protobuf_pyext_descriptor.cc,v 1.1 2019/01/06 11:21:06 markd Exp $

python3.7 fixes

--- python/google/protobuf/pyext/descriptor.cc.orig	2018-07-30 22:16:10.000000000 +0000
+++ python/google/protobuf/pyext/descriptor.cc
@@ -56,7 +56,7 @@
   #endif
   #define PyString_AsStringAndSize(ob, charpp, sizep) \
     (PyUnicode_Check(ob)? \
-       ((*(charpp) = PyUnicode_AsUTF8AndSize(ob, (sizep))) == NULL? -1: 0): \
+       ((*(charpp) = const_cast<char*>(PyUnicode_AsUTF8AndSize(ob, (sizep)))) == NULL? -1: 0): \
        PyBytes_AsStringAndSize(ob, (charpp), (sizep)))
 #endif
 
