$NetBSD: patch-src__c_pgcompat.h,v 1.1 2026/10/13 09:06:47 wiz Exp $

Python 3.15 support.
https://github.com/pygame/pygame/issues/4716

--- src_c/pgcompat.h.orig	2024-09-29 12:15:28.012112000 +0000
+++ src_c/pgcompat.h
@@ -24,4 +24,26 @@
 #define Slice_GET_INDICES_EX(slice, length, start, stop, step, slicelength) \
     PySlice_GetIndicesEx(slice, length, start, stop, step, slicelength)
 
+/* PyWeakref_GetObject() was removed in Python 3.15. PyWeakref_GetRef()
+ * (Python 3.13+) replaces it: returns 1 and a new reference if the referent
+ * is alive, 0 and NULL if it is dead, -1 and NULL on error. */
+#if PY_VERSION_HEX < 0x030D0000
+static inline int
+PyWeakref_GetRef(PyObject *ref, PyObject **pobj)
+{
+    PyObject *obj = PyWeakref_GetObject(ref);
+    if (obj == NULL) {
+        *pobj = NULL;
+        return -1;
+    }
+    if (obj == Py_None) {
+        *pobj = NULL;
+        return 0;
+    }
+    Py_INCREF(obj);
+    *pobj = obj;
+    return 1;
+}
+#endif
+
 #endif /* ~PGCOMPAT_INTERNAL_H */
