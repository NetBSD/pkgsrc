$NetBSD: patch-Modules___ssl.c,v 1.1.2.1 2013/08/21 11:47:14 tron Exp $

* from cygport 2.6.2-ssl-threads.patch

patch for CVE-2013-4238 taken from
http://hg.python.org/cpython/rev/bd2360476bdb

--- Modules/_ssl.c.orig	2013-04-06 14:02:36.000000000 +0000
+++ Modules/_ssl.c
@@ -16,6 +16,10 @@
 
 #include "Python.h"
 
+#ifdef __CYGWIN__
+#undef WITH_THREAD
+#endif
+
 #ifdef WITH_THREAD
 #include "pythread.h"
 #define PySSL_BEGIN_ALLOW_THREADS { \
@@ -738,13 +742,16 @@ _get_peer_alt_names (X509 *certificate) 
                                                   ext->value->length));
 
         for(j = 0; j < sk_GENERAL_NAME_num(names); j++) {
-
             /* get a rendering of each name in the set of names */
+            int gntype;
+            ASN1_STRING *as = NULL;
 
             name = sk_GENERAL_NAME_value(names, j);
-            if (name->type == GEN_DIRNAME) {
-
-                /* we special-case DirName as a tuple of tuples of attributes */
+            gntype = name-> type;
+            switch (gntype) {
+            case GEN_DIRNAME:
+                /* we special-case DirName as a tuple of
+                   tuples of attributes */
 
                 t = PyTuple_New(2);
                 if (t == NULL) {
@@ -764,11 +771,61 @@ _get_peer_alt_names (X509 *certificate) 
                     goto fail;
                 }
                 PyTuple_SET_ITEM(t, 1, v);
+                break;
 
-            } else {
+            case GEN_EMAIL:
+            case GEN_DNS:
+            case GEN_URI:
+                /* GENERAL_NAME_print() doesn't handle NULL bytes in ASN1_string
+                   correctly, CVE-2013-4238 */
+                t = PyTuple_New(2);
+                if (t == NULL)
+                    goto fail;
+                switch (gntype) {
+                case GEN_EMAIL:
+                    v = PyString_FromString("email");
+                    as = name->d.rfc822Name;
+                    break;
+                case GEN_DNS:
+                    v = PyString_FromString("DNS");
+                    as = name->d.dNSName;
+                    break;
+                case GEN_URI:
+                    v = PyString_FromString("URI");
+                    as = name->d.uniformResourceIdentifier;
+                    break;
+                }
+                if (v == NULL) {
+                    Py_DECREF(t);
+                    goto fail;
+                }
+                PyTuple_SET_ITEM(t, 0, v);
+                v = PyString_FromStringAndSize((char *)ASN1_STRING_data(as),
+                                               ASN1_STRING_length(as));
+                if (v == NULL) {
+                    Py_DECREF(t);
+                    goto fail;
+                }
+                PyTuple_SET_ITEM(t, 1, v);
+                break;
 
+            default:
                 /* for everything else, we use the OpenSSL print form */
-
+                switch (gntype) {
+                    /* check for new general name type */
+                    case GEN_OTHERNAME:
+                    case GEN_X400:
+                    case GEN_EDIPARTY:
+                    case GEN_IPADD:
+                    case GEN_RID:
+                        break;
+                    default:
+                        if (PyErr_Warn(PyExc_RuntimeWarning,
+                                       "Unknown general name type") == -1) {
+                            goto fail;
+                        }
+                        break;
+                }
                 (void) BIO_reset(biobuf);
                 GENERAL_NAME_print(biobuf, name);
                 len = BIO_gets(biobuf, buf, sizeof(buf)-1);
@@ -794,6 +851,7 @@ _get_peer_alt_names (X509 *certificate) 
                     goto fail;
                 }
                 PyTuple_SET_ITEM(t, 1, v);
+                break;
             }
 
             /* and add that rendering to the list */
