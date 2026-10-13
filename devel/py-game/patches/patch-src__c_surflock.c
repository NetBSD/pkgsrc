$NetBSD: patch-src__c_surflock.c,v 1.1 2026/10/13 09:06:48 wiz Exp $

Python 3.15 support.
https://github.com/pygame/pygame/issues/4716

--- src_c/surflock.c.orig	2024-09-29 12:15:28.016111900 +0000
+++ src_c/surflock.c
@@ -121,11 +121,16 @@ pgSurface_UnlockBy(pgSurfaceObject *surfobj, PyObject 
 
     if (surf->locklist != NULL) {
         PyObject *item, *ref;
+        int alive, match;
         Py_ssize_t len = PyList_Size(surf->locklist);
         while (--len >= 0 && !found) {
             item = PyList_GetItem(surf->locklist, len);
-            ref = PyWeakref_GetObject(item);
-            if (ref == lockobj) {
+            if (PyWeakref_GetRef(item, &ref) < 0) {
+                return 0;
+            }
+            match = (ref == lockobj);
+            Py_XDECREF(ref);
+            if (match) {
                 if (PySequence_DelItem(surf->locklist, len) == -1) {
                     return 0;
                 }
@@ -139,8 +144,13 @@ pgSurface_UnlockBy(pgSurfaceObject *surfobj, PyObject 
         len = PyList_Size(surf->locklist);
         while (--len >= 0) {
             item = PyList_GetItem(surf->locklist, len);
-            ref = PyWeakref_GetObject(item);
-            if (ref == Py_None) {
+            alive = PyWeakref_GetRef(item, &ref);
+            if (alive < 0) {
+                noerror = 0;
+                continue;
+            }
+            Py_XDECREF(ref);
+            if (!alive) {
                 if (PySequence_DelItem(surf->locklist, len) == -1) {
                     noerror = 0;
                 }
