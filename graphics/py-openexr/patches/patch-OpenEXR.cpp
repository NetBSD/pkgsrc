$NetBSD: patch-OpenEXR.cpp,v 1.2 2021/07/08 21:23:23 markd Exp $

Avoid CS define on SunOS.
openexr3 deprecates Int64

--- OpenEXR.cpp.orig	2018-08-30 14:53:51.000000000 +0000
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
@@ -44,6 +48,7 @@ typedef int Py_ssize_t;
 #include <ImfChannelListAttribute.h>
 #include <ImfChromaticitiesAttribute.h>
 #include <ImfCompressionAttribute.h>
+#include <ImfFrameBuffer.h>
 #include <ImfDoubleAttribute.h>
 #include <ImfEnvmapAttribute.h>
 #include <ImfFloatAttribute.h>
@@ -72,6 +77,7 @@ typedef int Py_ssize_t;
 #include <iostream>
 #include <iomanip>
 #include <iostream>
+#include <fstream>
 #include <vector>
 
 using namespace std;
@@ -105,8 +111,8 @@ class C_IStream: public IStream
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
@@ -132,7 +138,7 @@ const char* C_IStream::fileName() const
 }
 
 
-Int64
+uint64_t
 C_IStream::tellg ()
 {
     PyObject *rv = PyObject_CallMethod(_fo, (char*)"tell", NULL);
@@ -141,14 +147,14 @@ C_IStream::tellg ()
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
@@ -170,8 +176,8 @@ class C_OStream: public OStream
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
@@ -196,7 +202,7 @@ const char* C_OStream::fileName() const
 }
 
 
-Int64
+uint64_t
 C_OStream::tellp ()
 {
     PyObject *rv = PyObject_CallMethod(_fo, (char*)"tell", NULL);
@@ -205,14 +211,14 @@ C_OStream::tellp ()
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
