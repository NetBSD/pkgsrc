$NetBSD: patch-zstd.c,v 1.1 2018/10/22 15:32:01 adam Exp $

Allow newer zstd.

--- zstd.c.orig	2018-10-22 15:14:29.000000000 +0000
+++ zstd.c
@@ -210,10 +210,6 @@ void zstd_module_init(PyObject* m) {
 	   We detect this mismatch here and refuse to load the module if this
 	   scenario is detected.
 	*/
-	if (ZSTD_VERSION_NUMBER != 10306 || ZSTD_versionNumber() != 10306) {
-		PyErr_SetString(PyExc_ImportError, "zstd C API mismatch; Python bindings not compiled against expected zstd version");
-		return;
-	}
 
 	bufferutil_module_init(m);
 	compressionparams_module_init(m);
@@ -341,4 +337,4 @@ int safe_pybytes_resize(PyObject** obj, 
 	*obj = tmp;
 
 	return 0;
-}
\ No newline at end of file
+}
