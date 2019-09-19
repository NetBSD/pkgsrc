$NetBSD: patch-zstd.c,v 1.3 2019/09/19 16:50:57 adam Exp $

Allow newer zstd.

--- zstd.c.orig	2019-09-16 01:27:27.000000000 +0000
+++ zstd.c
@@ -210,10 +210,6 @@ void zstd_module_init(PyObject* m) {
 	   We detect this mismatch here and refuse to load the module if this
 	   scenario is detected.
 	*/
-	if (ZSTD_VERSION_NUMBER != 10403 || ZSTD_versionNumber() != 10403) {
-		PyErr_SetString(PyExc_ImportError, "zstd C API mismatch; Python bindings not compiled against expected zstd version");
-		return;
-	}
 
 	bufferutil_module_init(m);
 	compressionparams_module_init(m);
