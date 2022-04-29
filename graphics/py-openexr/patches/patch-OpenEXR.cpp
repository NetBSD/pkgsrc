$NetBSD: patch-OpenEXR.cpp,v 1.3 2022/04/29 12:07:43 adam Exp $

Avoid CS define on SunOS.
openexr3 deprecates Int64

--- OpenEXR.cpp.orig	2022-04-17 06:27:41.000000000 +0000
+++ OpenEXR.cpp
@@ -1,5 +1,9 @@
 #include <Python.h>
 
+#ifdef __sun
+#undef CS
+#endif
+
 #if PY_VERSION_HEX < 0x02050000 && !defined(PY_SSIZE_T_MIN)
 typedef int Py_ssize_t;
 #define PY_SSIZE_T_MAX INT_MAX
@@ -43,6 +47,7 @@ typedef int Py_ssize_t;
 #include <ImfChannelListAttribute.h>
 #include <ImfChromaticitiesAttribute.h>
 #include <ImfCompressionAttribute.h>
+#include <ImfFrameBuffer.h>
 #include <ImfDoubleAttribute.h>
 #include <ImfEnvmapAttribute.h>
 #include <ImfFloatAttribute.h>
@@ -73,6 +78,7 @@ typedef int Py_ssize_t;
 #include <iostream>
 #include <iomanip>
 #include <iostream>
+#include <fstream>
 #include <vector>
 
 #define IMATH_VERSION IMATH_VERSION_MAJOR * 10000 + \
@@ -115,8 +121,8 @@ class C_IStream: public IStream
     C_IStream (PyObject *fo):
         IStream(""), _fo(fo) {}
     virtual bool    read (char c[], int n);
-    virtual Int64   tellg ();
-    virtual void    seekg (Int64 pos);
+    virtual uint64_t   tellg ();
+    virtual void    seekg (uint64_t pos);
     virtual void    clear ();
     virtual const char*     fileName() const;
   private:
@@ -142,7 +148,7 @@ const char* C_IStream::fileName() const
 }
 
 
-Int64
+uint64_t
 C_IStream::tellg ()
 {
     PyObject *rv = PyObject_CallMethod(_fo, (char*)"tell", NULL);
@@ -151,14 +157,14 @@ C_IStream::tellg ()
       long long t = PyLong_AsLong(lrv);
       Py_DECREF(lrv);
       Py_DECREF(rv);
-      return (Int64)t;
+      return (uint64_t)t;
     } else {
       throw Iex::InputExc("tell failed");
     }
 }
 
 void
-C_IStream::seekg (Int64 pos)
+C_IStream::seekg (uint64_t pos)
 {
     PyObject *data = PyObject_CallMethod(_fo, (char*)"seek", (char*)"(L)", pos);
     if (data != NULL) {
@@ -180,8 +186,8 @@ class C_OStream: public OStream
   public:
     C_OStream (PyObject *fo): OStream(""), _fo(fo) {}
     virtual void    write (const char *c, int n);
-    virtual Int64   tellp ();
-    virtual void    seekp (Int64 pos);
+    virtual uint64_t   tellp ();
+    virtual void    seekp (uint64_t pos);
     virtual void    clear ();
     virtual const char*     fileName() const;
   private:
@@ -206,7 +212,7 @@ const char* C_OStream::fileName() const
 }
 
 
-Int64
+uint64_t
 C_OStream::tellp ()
 {
     PyObject *rv = PyObject_CallMethod(_fo, (char*)"tell", NULL);
@@ -215,14 +221,14 @@ C_OStream::tellp ()
       long long t = PyLong_AsLong(lrv);
       Py_DECREF(lrv);
       Py_DECREF(rv);
-      return (Int64)t;
+      return (uint64_t)t;
     } else {
       throw Iex::InputExc("tell failed");
     }
 }
 
 void
-C_OStream::seekp (Int64 pos)
+C_OStream::seekp (uint64_t pos)
 {
     PyObject *data = PyObject_CallMethod(_fo, (char*)"seek", (char*)"(L)", pos);
     if (data != NULL) {
