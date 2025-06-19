$NetBSD: patch-python_pyglue.c,v 1.1 2025/06/19 02:08:47 gutteridge Exp $

Account for platforms that don't define ENOTRECOVERABLE, like NetBSD
before 10.0.

--- python/pyglue.c.orig	2025-02-17 15:48:20.614155500 +0000
+++ python/pyglue.c
@@ -538,7 +538,11 @@ static PyObject *py_crypt(PyObject *self
 	ret = talloc_crypt_blob(frame, phrase, setting, &hash);
 	if (ret != 0) {
 		const char *errstr = talloc_crypt_errstring(frame, ret);
+#ifdef ENOTRECOVERABLE
 		if (ret == EINVAL || ret == ERANGE || ret == ENOTRECOVERABLE) {
+#else
+		if (ret == EINVAL || ret == ERANGE || ret == ENOSYS) {
+#endif
 			PyErr_Format(PyExc_ValueError,
 				     "could not crypt(): %s",
 				     errstr);
