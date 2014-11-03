$NetBSD: patch-Objects_unicodeobject.c,v 1.1.2.2 2014/11/03 14:12:52 tron Exp $

taken from https://hg.python.org/cpython/rev/b2e68274aa8e:

Issue #22518: integer overflow in encoding unicode

--- Objects/unicodeobject.c.orig	2014-06-30 02:05:45.000000000 +0000
+++ Objects/unicodeobject.c
@@ -1510,9 +1510,15 @@ int unicode_decode_call_errorhandler(con
        when there are no errors in the rest of the string) */
     repptr = PyUnicode_AS_UNICODE(repunicode);
     repsize = PyUnicode_GET_SIZE(repunicode);
-    requiredsize = *outpos + repsize + insize-newpos;
+    requiredsize = *outpos;
+    if (requiredsize > PY_SSIZE_T_MAX - repsize)
+        goto overflow;
+    requiredsize += repsize;
+    if (requiredsize > PY_SSIZE_T_MAX - (insize - newpos))
+        goto overflow;
+    requiredsize += insize - newpos;
     if (requiredsize > outsize) {
-        if (requiredsize<2*outsize)
+        if (outsize <= PY_SSIZE_T_MAX/2 && requiredsize < 2*outsize)
             requiredsize = 2*outsize;
         if (_PyUnicode_Resize(output, requiredsize) < 0)
             goto onError;
@@ -1529,6 +1535,11 @@ int unicode_decode_call_errorhandler(con
   onError:
     Py_XDECREF(restuple);
     return res;
+
+  overflow:
+    PyErr_SetString(PyExc_OverflowError,
+                    "decoded result is too long for a Python string");
+    goto onError;
 }
 
 /* --- UTF-7 Codec -------------------------------------------------------- */
@@ -3646,7 +3657,7 @@ static PyObject *unicode_encode_ucs1(con
             const Py_UNICODE *collstart = p;
             const Py_UNICODE *collend = p;
             /* find all unecodable characters */
-            while ((collend < endp) && ((*collend)>=limit))
+            while ((collend < endp) && ((*collend) >= limit))
                 ++collend;
             /* cache callback name lookup (if not done yet, i.e. it's the first error) */
             if (known_errorHandler==-1) {
@@ -3666,34 +3677,41 @@ static PyObject *unicode_encode_ucs1(con
                 raise_encode_exception(&exc, encoding, startp, size, collstart-startp, collend-startp, reason);
                 goto onError;
             case 2: /* replace */
-                while (collstart++<collend)
+                while (collstart++ < collend)
                     *str++ = '?'; /* fall through */
             case 3: /* ignore */
                 p = collend;
                 break;
             case 4: /* xmlcharrefreplace */
-                respos = str-PyString_AS_STRING(res);
+                respos = str - PyString_AS_STRING(res);
                 /* determine replacement size (temporarily (mis)uses p) */
-                for (p = collstart, repsize = 0; p < collend;) {
+                requiredsize = respos;
+                for (p = collstart; p < collend;) {
                     Py_UCS4 ch = _Py_UNICODE_NEXT(p, collend);
+                    Py_ssize_t incr;
                     if (ch < 10)
-                        repsize += 2+1+1;
+                        incr = 2+1+1;
                     else if (ch < 100)
-                        repsize += 2+2+1;
+                        incr = 2+2+1;
                     else if (ch < 1000)
-                        repsize += 2+3+1;
+                        incr = 2+3+1;
                     else if (ch < 10000)
-                        repsize += 2+4+1;
+                        incr = 2+4+1;
                     else if (ch < 100000)
-                        repsize += 2+5+1;
+                        incr = 2+5+1;
                     else if (ch < 1000000)
-                        repsize += 2+6+1;
+                        incr = 2+6+1;
                     else
-                        repsize += 2+7+1;
-                }
-                requiredsize = respos+repsize+(endp-collend);
+                        incr = 2+7+1;
+                    if (requiredsize > PY_SSIZE_T_MAX - incr)
+                        goto overflow;
+                    requiredsize += incr;
+                }
+                if (requiredsize > PY_SSIZE_T_MAX - (endp - collend))
+                    goto overflow;
+                requiredsize += endp - collend;
                 if (requiredsize > ressize) {
-                    if (requiredsize<2*ressize)
+                    if (ressize <= PY_SSIZE_T_MAX/2 && requiredsize < 2*ressize)
                         requiredsize = 2*ressize;
                     if (_PyString_Resize(&res, requiredsize))
                         goto onError;
@@ -3716,11 +3734,16 @@ static PyObject *unicode_encode_ucs1(con
                 /* need more space? (at least enough for what we have+the
                    replacement+the rest of the string, so we won't have to
                    check space for encodable characters) */
-                respos = str-PyString_AS_STRING(res);
+                respos = str - PyString_AS_STRING(res);
                 repsize = PyUnicode_GET_SIZE(repunicode);
-                requiredsize = respos+repsize+(endp-collend);
+                if (respos > PY_SSIZE_T_MAX - repsize)
+                    goto overflow;
+                requiredsize = respos + repsize;
+                if (requiredsize > PY_SSIZE_T_MAX - (endp - collend))
+                    goto overflow;
+                requiredsize += endp - collend;
                 if (requiredsize > ressize) {
-                    if (requiredsize<2*ressize)
+                    if (ressize <= PY_SSIZE_T_MAX/2 && requiredsize < 2*ressize)
                         requiredsize = 2*ressize;
                     if (_PyString_Resize(&res, requiredsize)) {
                         Py_DECREF(repunicode);
@@ -3731,7 +3754,7 @@ static PyObject *unicode_encode_ucs1(con
                 }
                 /* check if there is anything unencodable in the replacement
                    and copy it to the output */
-                for (uni2 = PyUnicode_AS_UNICODE(repunicode);repsize-->0; ++uni2, ++str) {
+                for (uni2 = PyUnicode_AS_UNICODE(repunicode); repsize-->0; ++uni2, ++str) {
                     c = *uni2;
                     if (c >= limit) {
                         raise_encode_exception(&exc, encoding, startp, size,
@@ -3747,14 +3770,18 @@ static PyObject *unicode_encode_ucs1(con
         }
     }
     /* Resize if we allocated to much */
-    respos = str-PyString_AS_STRING(res);
-    if (respos<ressize)
+    respos = str - PyString_AS_STRING(res);
+    if (respos < ressize)
         /* If this falls res will be NULL */
         _PyString_Resize(&res, respos);
     Py_XDECREF(errorHandler);
     Py_XDECREF(exc);
     return res;
 
+  overflow:
+    PyErr_SetString(PyExc_OverflowError,
+                    "encoded result is too long for a Python string");
+
   onError:
     Py_XDECREF(res);
     Py_XDECREF(errorHandler);
