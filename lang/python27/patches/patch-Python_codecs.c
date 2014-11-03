$NetBSD: patch-Python_codecs.c,v 1.1.2.2 2014/11/03 14:12:52 tron Exp $

taken from https://hg.python.org/cpython/rev/3f7519f633ed and
https://hg.python.org/cpython/rev/d1be1f355f59:

Issue #22518: Fixed integer overflow issues in "backslashreplace"
and "xmlcharrefreplace" error handlers.

--- Python/codecs.c.orig	2014-06-30 02:05:46.000000000 +0000
+++ Python/codecs.c
@@ -558,7 +558,7 @@ PyObject *PyCodec_XMLCharRefReplaceError
         Py_UNICODE *startp;
         Py_UNICODE *e;
         Py_UNICODE *outp;
-        int ressize;
+        Py_ssize_t ressize;
         if (PyUnicodeEncodeError_GetStart(exc, &start))
             return NULL;
         if (PyUnicodeEncodeError_GetEnd(exc, &end))
@@ -566,6 +566,13 @@ PyObject *PyCodec_XMLCharRefReplaceError
         if (!(object = PyUnicodeEncodeError_GetObject(exc)))
             return NULL;
         startp = PyUnicode_AS_UNICODE(object);
+        if (end - start > PY_SSIZE_T_MAX / (2+7+1)) {
+            end = start + PY_SSIZE_T_MAX / (2+7+1);
+#ifndef Py_UNICODE_WIDE
+            if (0xD800 <= startp[end - 1] && startp[end - 1] <= 0xDBFF)
+                end--;
+#endif
+        }
         e = startp + end;
         for (p = startp+start, ressize = 0; p < e;) {
             Py_UCS4 ch = *p++;
@@ -675,13 +682,15 @@ PyObject *PyCodec_BackslashReplaceErrors
         Py_UNICODE *p;
         Py_UNICODE *startp;
         Py_UNICODE *outp;
-        int ressize;
+        Py_ssize_t ressize;
         if (PyUnicodeEncodeError_GetStart(exc, &start))
             return NULL;
         if (PyUnicodeEncodeError_GetEnd(exc, &end))
             return NULL;
         if (!(object = PyUnicodeEncodeError_GetObject(exc)))
             return NULL;
+        if (end - start > PY_SSIZE_T_MAX / (1+1+8))
+            end = start + PY_SSIZE_T_MAX / (1+1+8);
         startp = PyUnicode_AS_UNICODE(object);
         for (p = startp+start, ressize = 0; p < startp+end; ++p) {
 #ifdef Py_UNICODE_WIDE
