$NetBSD: patch-Modules___multiprocessing_semaphore.c,v 1.1 2016/07/11 12:17:13 ryoon Exp $

--- Modules/_multiprocessing/semaphore.c.orig	2016-06-25 21:49:31.000000000 +0000
+++ Modules/_multiprocessing/semaphore.c
@@ -424,7 +424,11 @@ newsemlockobject(PyTypeObject *type, SEM
 static PyObject *
 semlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
 {
+#if defined(__NetBSD__)
+    char buffer[15];
+#else
     char buffer[256];
+#endif
     SEM_HANDLE handle = SEM_FAILED;
     int kind, maxvalue, value;
     PyObject *result;
@@ -444,10 +448,19 @@ semlock_new(PyTypeObject *type, PyObject
      * _PyOS_URandom() are treated as unsigned long to ensure that the filename
      * is valid (no special characters). */
     do {
+#if defined(__NetBSD__)
+        unsigned char suffix1;
+        unsigned char suffix2;
+        _PyOS_URandom((char *)&suffix1, sizeof(suffix1));
+        _PyOS_URandom((char *)&suffix2, sizeof(suffix2));
+        PyOS_snprintf(buffer, sizeof(buffer), "/mp%ld-%x%x", (long)getpid(),
+                      suffix1, suffix2);
+#else
         unsigned long suffix;
         _PyOS_URandom((char *)&suffix, sizeof(suffix));
         PyOS_snprintf(buffer, sizeof(buffer), "/mp%ld-%lu", (long)getpid(),
                       suffix);
+#endif
         SEM_CLEAR_ERROR();
         handle = SEM_CREATE(buffer, value, maxvalue);
     } while ((handle == SEM_FAILED) && (errno == EEXIST) && (++try < 100));
