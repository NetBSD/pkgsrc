$NetBSD: patch-src_file__compat.h,v 1.1 2018/07/11 16:19:32 gson Exp $

Do not call the flush method on a file object opened for reading,
bcause it returns an error on BSD systems, with the end result
that importing matplotlib fails as reported in PR pkg/53425.

--- src/file_compat.h.orig	2018-03-06 04:47:09.000000000 +0000
+++ src/file_compat.h
@@ -60,12 +60,15 @@ static NPY_INLINE FILE *mpl_PyFile_Dup(P
     mpl_off_t pos;
     FILE *handle;
 
-    /* Flush first to ensure things end up in the file in the correct order */
-    ret = PyObject_CallMethod(file, (char *)"flush", (char *)"");
-    if (ret == NULL) {
-        return NULL;
+    if (mode[0] != 'r') {
+        /* Flush first to ensure things end up in the file in the correct order */
+        ret = PyObject_CallMethod(file, (char *)"flush", (char *)"");
+        if (ret == NULL) {
+            return NULL;
+        }
+        Py_DECREF(ret);
     }
-    Py_DECREF(ret);
+
     fd = PyObject_AsFileDescriptor(file);
     if (fd == -1) {
         return NULL;
