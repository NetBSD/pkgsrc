$NetBSD: patch-src__c_surface.c,v 1.1 2026/10/13 09:06:48 wiz Exp $

Python 3.15 support.
https://github.com/pygame/pygame/issues/4716

--- src_c/surface.c.orig	2024-09-29 12:15:28.016111900 +0000
+++ src_c/surface.c
@@ -1020,8 +1020,14 @@ surf_get_locks(PyObject *self, PyObject *_null)
         return NULL;
 
     for (i = 0; i < len; i++) {
-        tmp = PyWeakref_GetObject(PyList_GetItem(surf->locklist, i));
-        Py_INCREF(tmp);
+        if (PyWeakref_GetRef(PyList_GetItem(surf->locklist, i), &tmp) < 0) {
+            Py_DECREF(tuple);
+            return NULL;
+        }
+        if (tmp == NULL) { /* dead lock owner: report None, as before */
+            tmp = Py_None;
+            Py_INCREF(tmp);
+        }
         PyTuple_SetItem(tuple, i, tmp);
     }
     return tuple;
@@ -3443,11 +3449,17 @@ _release_buffer(Py_buffer *view_p)
     internal = (pg_bufferinternal *)view_p->internal;
     consumer_ref = internal->consumer_ref;
     assert(consumer_ref && PyWeakref_CheckRef(consumer_ref));
-    consumer = PyWeakref_GetObject(consumer_ref);
-    if (consumer) {
-        if (!pgSurface_UnlockBy((pgSurfaceObject *)view_p->obj, consumer)) {
+    if (PyWeakref_GetRef(consumer_ref, &consumer) < 0) {
+        PyErr_Clear();
+    }
+    else {
+        /* A dead consumer is passed as None, as PyWeakref_GetObject() did,
+         * so UnlockBy still purges its dead lock entry. */
+        if (!pgSurface_UnlockBy((pgSurfaceObject *)view_p->obj,
+                                consumer ? consumer : Py_None)) {
             PyErr_Clear();
         }
+        Py_XDECREF(consumer);
     }
     Py_DECREF(consumer_ref);
     PyMem_Free(internal);
