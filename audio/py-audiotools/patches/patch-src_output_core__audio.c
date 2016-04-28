$NetBSD: patch-src_output_core__audio.c,v 1.1 2016/04/28 19:23:21 adam Exp $

Fix building with Python 3.x.

--- src/output/core_audio.c.orig	2015-10-31 21:51:57.000000000 +0000
+++ src/output/core_audio.c
@@ -95,31 +95,10 @@ CoreAudio_init(output_CoreAudio *self, P
           at init-time, we'll need to temporarily redirect
           stdout to /dev/null*/
 
-        /*first, determine the location of /dev/null from os.devnull*/
-        if ((os_module_obj = PyImport_ImportModule("os")) == NULL) {
-            return -1;
-        }
-        if ((devnull_obj =
-             PyObject_GetAttrString(os_module_obj, "devnull")) == NULL) {
-            Py_DECREF(os_module_obj);
-            return -1;
-        }
-        if ((devnull = PyString_AsString(devnull_obj)) == NULL) {
-            Py_DECREF(os_module_obj);
-            Py_DECREF(devnull_obj);
-            return -1;
-        }
-
         /*open /dev/null*/
-        if ((devnull_stdout = open(devnull, O_WRONLY | O_TRUNC)) == -1) {
-            Py_DECREF(os_module_obj);
-            Py_DECREF(devnull_obj);
+        if ((devnull_stdout = open("/dev/null", O_WRONLY | O_TRUNC)) == -1) {
             PyErr_SetFromErrno(PyExc_IOError);
             return -1;
-        } else {
-            /*close unneeded Python objects once descriptor is open*/
-            Py_DECREF(os_module_obj);
-            Py_DECREF(devnull_obj);
         }
 
         /*swap file descriptors*/
